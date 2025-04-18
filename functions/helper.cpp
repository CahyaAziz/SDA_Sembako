#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "auth.h"
#include "helper.h"

using namespace std;

#define MAX_USERS 50

void saveUser(const akun& user, const string& filename) {
    ofstream file(filename, ios::app); // append mode
    if (file.is_open()) {
        file << user.NIK << "," 
             << user.nama << "," 
             << user.jenisKelamin << "," 
             << user.umur << "," 
             << user.password << "," 
             << (user.queue ? "1" : "0") << "," 
             << (user.menerima ? "1" : "0") << "\n";
        file.close();
    } else {
        cerr << "Error membuka file untuk menyimpan data!" << endl;
    }
}

int loadUsers(akun users[], const string& filename) {
    ifstream file(filename);
    string line;
    int count = 0;

    if (!file.is_open()) {
        cerr << "Error membuka file untuk membaca data!" << endl;
        return count;
    }

    while (getline(file, line) && count < MAX_USERS) {
        stringstream ss(line);
        akun u;
        string umurStr, queueStr, menerimaStr;

        getline(ss, u.NIK, ',');
        getline(ss, u.nama, ',');
        string jenisKelaminStr;
        getline(ss, jenisKelaminStr, ',');
        u.jenisKelamin = jenisKelaminStr[0];
        getline(ss, umurStr, ',');
        getline(ss, u.password, ',');
        getline(ss, queueStr, ',');
        getline(ss, menerimaStr, ',');

        u.umur = stoi(umurStr);
        u.queue = (queueStr == "1");
        u.menerima = (menerimaStr == "1");

        users[count++] = u;
    }

    file.close();
    return count;
}

vector<Sembako> loadSembako(const string& filename) {
    vector<Sembako> daftar;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Sembako item;
        string stokStr;

        getline(ss, item.nama, ',');
        getline(ss, stokStr, ',');
        item.stok = stoi(stokStr);

        daftar.push_back(item);
    }

    return daftar;
}

bool isPenerima(const string& NIK) {
    akun users[MAX_USERS];
    int userCount = loadUsers(users, "users.csv");
    for (int i = 0; i < userCount; ++i) {
        if (users[i].NIK == NIK && !users[i].menerima) {
            return true;
        }
    }
    return false;
}

void updateStatus(const string& NIK, bool queueState) {
    akun users[MAX_USERS];
    int userCount = loadUsers(users, "users.csv");

    for (int i = 0; i < userCount; ++i) {
        if (users[i].NIK == NIK) {
            if (queueState == true) {
                if (users[i].queue) {
                    users[i].menerima = true; // Mark as received if queue is false
                } else {
                    users[i].queue = queueState;
                }
            } else if (queueState == false) {
                users[i].queue = queueState;
            }
            break;
        }
    }

    // Tulis ulang file
    ofstream file("users.csv");
    if (!file.is_open()) {
        cerr << "Error membuka file users.csv untuk menulis ulang data!" << endl;
        return;
    }

    for (int i = 0; i < userCount; ++i) {
        file << users[i].NIK << ","
             << users[i].nama << ","
             << users[i].jenisKelamin << ","
             << users[i].umur << ","
             << users[i].password << ","
             << (users[i].queue ? "1" : "0") << ","
             << (users[i].menerima ? "1" : "0") << "\n";
    }

    file.close();
}

bool isUserInQueue(const string& NIK) {
    akun users[MAX_USERS];
    int userCount = loadUsers(users, "users.csv");
    for (int i = 0; i < userCount; ++i) {
        if (users[i].NIK == NIK && users[i].queue) {
            return true;
        }
    }
    return false;
}

void saveStok(const vector<Sembako>& daftar) {
    ofstream file("stock.csv");
    if (!file.is_open()) {
        cout << "Gagal menyimpan stok ke file.\n";
        return;
    }

    for (const Sembako& item : daftar) {
        file << item.nama << "," << item.stok << "\n";
    }

    file.close();
}

/* vector<Sembako> loadStokFromCSV() {
    vector<Sembako> daftar;
    ifstream file("stock.csv");
    if (!file.is_open()) {
        cout << "Gagal membuka file stok.csv.\n";
        return daftar;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string nama, stokStr;
        getline(ss, nama, ',');
        getline(ss, stokStr);

        if (!nama.empty() && !stokStr.empty()) {
            Sembako item;
            item.nama = nama;
            item.stok = stoi(stokStr);
            daftar.push_back(item);
        }
    }

    file.close();
    return daftar;
} */
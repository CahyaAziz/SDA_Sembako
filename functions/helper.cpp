#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "auth.h"
#include "helper.h"

using namespace std;

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

vector<akun> loadUsers(const string& filename) {
    vector<akun> users;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Error membuka file untuk membaca data!" << endl;
        return users;
    }

    while (getline(file, line)) {
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

        users.push_back(u);
    }

    file.close();
    return users;
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
    vector<akun> users = loadUsers();
    for (const akun& u : users) {
        if (u.NIK == NIK && !u.menerima) {
            return true;
        }
    }
    return false;
}

void updateStatus(const string& NIK) {
    vector<akun> users = loadUsers();
    for (akun& u : users) {
        if (u.NIK == NIK) {
            if (u.queue) {
                u.menerima = true;
                break;
            } else {
                u.queue = true;
            }
        }
    }

    // Tulis ulang file
    ofstream file("users.csv");
    for (const akun& u : users) {
        file << u.NIK << ","
             << u.nama << ","
             << u.jenisKelamin << ","
             << u.umur << ","
             << u.password << ","
             << (u.queue ? "1" : "0") << ","
             << (u.menerima ? "1" : "0") << "\n";
    }
}

bool isUserInQueue(const string& NIK) {
    vector<akun> users = loadUsers(); // Assuming loadUsers loads user data
    for (const akun& user : users) {
        if (user.NIK == NIK && user.queue) {
            return true;
        }
    }
    return false;
}


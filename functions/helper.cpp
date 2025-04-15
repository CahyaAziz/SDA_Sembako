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
             << (user.menerima ? "1" : "0") << "\n";
        file.close();
        cout << "Data user berhasil disimpan ke file " << filename << endl;
    } else {
        cout << "Error membuka file untuk menyimpan data!" << endl;
    }
}

vector<akun> loadUsers(const string& filename) {
    vector<akun> users;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        akun u;
        string umurStr, menerimaStr;

        getline(ss, u.NIK, ',');
        getline(ss, u.nama, ',');
        string jenisKelaminStr;
        getline(ss, jenisKelaminStr, ',');
        u.jenisKelamin = jenisKelaminStr[0];
        getline(ss, umurStr, ',');
        getline(ss, u.password, ',');
        getline(ss, menerimaStr, ',');

        u.umur = stoi(umurStr);
        u.menerima = (menerimaStr == "1");

        users.push_back(u);
    }

    return users;
}

bool isPenerima(const std::string& nama) {
    std::vector<akun> users = loadUsers();
    for (const akun& u : users) {
        if (u.nama == nama && u.menerima) {
            return true;
        }
    }
    return false;
}

void updateStatus(const std::string& nama) {
    std::vector<akun> users = loadUsers();
    for (akun& u : users) {
        if (u.nama == nama) {
            u.menerima = true;
            break;
        }
    }

    // Tulis ulang file
    std::ofstream file("users.csv");
    for (const akun& u : users) {
        file << u.NIK << ","
            << u.nama << ","
            << u.jenisKelamin << ","
            << u.umur << ","
            << u.password << ","
            << (u.menerima ? "1" : "0") << "\n";
    }
}


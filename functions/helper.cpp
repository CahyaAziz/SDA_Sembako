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
             << user.menerima << "\n";
        file.close();
        cout << "Data user berhasil di save" << filename << endl;
    } else {
        cout << "Error opening file for writing!" << endl;
    }
}

vector<akun> loadUsers(const string& filename) {
    vector<akun> users;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        akun u;
        string umurStr;

        getline(ss, u.NIK, ',');
        getline(ss, u.nama, ',');
        ss >> u.jenisKelamin;
        ss.ignore(); // skip comma
        getline(ss, umurStr, ',');
        u.umur = stoi(umurStr);
        getline(ss, u.password, ',');
        string menerimaStr;
        getline(ss, menerimaStr, ',');
        u.menerima = (menerimaStr == "1" || menerimaStr == "true");

        users.push_back(u);
    }

    return users;
}
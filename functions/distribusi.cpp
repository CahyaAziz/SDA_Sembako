#include <iostream>
#include <vector>
#include "auth.h"
#include "helper.h"

using namespace std;

void tampilkanRiwayatDistribusi() {
    vector<akun> users = loadUsers();

    cout << "\n=== Daftar Riwayat Distribusi Sembako ===\n";
    bool adaYangMenerima = false;

    for (const akun& user : users) {
        if (user.menerima) {
            if (!adaYangMenerima) {
                cout << "Yang Sudah Menerima:\n";
                adaYangMenerima = true;
            }
            cout << "- " << user.nama << " (NIK: " << user.NIK << ")\n";
        }
    }

    if (!adaYangMenerima) {
        cout << "Belum ada warga yang menerima sembako.\n";
    }

    cout << endl;
}


#include <iostream>
#include <vector>
#include "auth.h"
#include "helper.h"

using namespace std;

void tampilkanRiwayatDistribusi() {
    akun users[MAX_USERS];
    int userCount = loadUsers(users);

    cout << "\n=== Daftar Riwayat Distribusi Sembako ===\n";
    bool adaYangMenerima = false;

    for (int i = 0; i < userCount; ++i) {
        if (users[i].menerima) {
            if (!adaYangMenerima) {
                cout << "Yang Sudah Menerima:\n";
                adaYangMenerima = true;
            }
            cout << "- " << users[i].nama << " (NIK: " << users[i].NIK << ")\n";
        }
    }

    if (!adaYangMenerima) {
        cout << "Belum ada warga yang menerima sembako.\n";
    }

    cout << endl;
}


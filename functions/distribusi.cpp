#include <iostream>
#include <vector>
#include "auth.h"
#include "helper.h"
#include "distribusi.h"

using namespace std;

void tampilkanRiwayatDistribusi() {
    vector<akun> users = loadUsers();

    cout << "\n=== Daftar Riwayat Distribusi Sembako ===\n";
    cout << "Yang Sudah Menerima:\n";
    for (const akun& user : users) {
        if (user.menerima) {
            cout << "- " << user.nama << " (NIK: " << user.NIK << ")\n";
        }
    }

    cout << endl;
}

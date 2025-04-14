// stock.cpp
#include "stock.h"
#include <iostream>
using namespace std;

void tampilanStok(const vector<Sembako>& daftar) {
    cout << "\n=== Daftar Stok Sembako ===\n";
    for (size_t i = 0; i < daftar.size(); ++i) {
        cout << i + 1 << ". " << daftar[i].nama << " - Stok: " << daftar[i].stok << endl;
    }
}

void editStok(vector<Sembako>& daftar) {
    int pilihan;
    tampilanStok(daftar);
    cout << "\nPilih nomor sembako yang ingin diedit: ";
    cin >> pilihan;

    if (pilihan < 1 || pilihan > daftar.size()) {
        cout << "Pilihan tidak valid!" << endl;
        return;
    }

    int tambah;
    cout << "Masukkan jumlah yang ingin ditambahkan atau dikurangi: ";
    cin >> tambah;

    daftar[pilihan - 1].stok += tambah;

    if (daftar[pilihan - 1].stok < 0) {
        daftar[pilihan - 1].stok = 0;
        cout << "Stok tidak boleh negatif. Ditetapkan menjadi 0.\n";
    } else {
        cout << "Stok berhasil diperbarui.\n";
    }
}

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
};

int main() {
    vector<Sembako>daftar = {
        {"Beras", 100},
        {"Minyak Goreng", 50},
        {"Gula", 30},
        {"Susu", 20},
        {"Mie Instan", 200}
    };

    int menu;
    do {
        cout << "=== Menu Stok Sembako ===\n";
        cout << "1. Tampilkan Stok\n";
        cout << "2. Edit Stok\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 1:
                tampilanStok(daftar);
                break;
            case 2:
                editStok(daftar);
                break;
            case 3:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        } 
    } while (menu != 3);

    return 0;
}
// stock.cpp
#include "stock.h"
#include "helper.h"
#include "antrian.h"
#include <iostream>
using namespace std;

vector<pair<string, int>> minimum = {
    {"Beras", 5},
    {"Telur", 1},
    {"Minyak Goreng", 2},
    {"Gula", 1},
    {"Susu", 2},
    {"Mie Instan", 10}
};

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

bool checkStock(const vector<Sembako>& daftar, const vector<pair<string, int>>& minimums) {
    for (const auto& i : minimum) {
        string nama = i.first;
        int required = i.second;

        // Find the item in the daftar vector
        bool found = false;
        for (const Sembako& item : daftar) {
            if (item.nama == nama) {
                found = true;
                if (item.stok < required) {
                    cout << item.nama << " kurang dari minimum (" << item.stok << " / " << required << ")\n";
                    return false;
                }
                break;
            }
        }
        if (!found) {
            cout << "Item " << nama << " tidak ditemukan dalam stok.\n";
            return false;
        }
    }

    return true;
}

void terimaSembako(const vector<Sembako>& daftar, const string& NIK) {
    vector<akun> users = loadUsers();

    if (!(checkStock(daftar, minimum))) {
        cout << "Stock habis" << endl;
        return;
    }

    for (const akun& u : users) {
        if (u.NIK == NIK) {
            if (u.menerima) {
                cout << "Anda sudah menerima sembako." << endl;
                return;
            }
            if (u.queue) {
                cout << "\n=== Daftar Sembako ===\n";
                cout << "Beras - 5kg" << endl;
                cout << "Telur - 1kg" << endl;
                cout << "Minyak - 2L" << endl;
                cout << "Gula - 1kg" << endl;
                cout << "Susu - 2" << endl;
                cout << "Mie Instan - 10" << endl << endl;

                updateStatus(NIK);
                hapusAntrian();
            } else {
                cout << "Anda belum dipanggil! Silakan menunggu admin." << endl;
            }
            return;
        }
    }

    cout << "NIK tidak ditemukan." << endl;
}
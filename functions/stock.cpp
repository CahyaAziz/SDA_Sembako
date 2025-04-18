// stock.cpp
#include "stock.h"
#include "helper.h"
#include "antrian.h"
#include <iostream>
#include <fstream>
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

    saveStok(daftar);  // Simpan perubahan
}

bool checkStock(const vector<Sembako>& daftar, const vector<pair<string, int>>& minimums) {
    for (const auto& i : minimums) {
        string nama = i.first;
        int required = i.second;

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

void kurangiStok(vector<Sembako>& daftar, const vector<pair<string, int>>& minimums) {
    for (auto& i : daftar) {
        for (const auto& min : minimums) {
            if (i.nama == min.first) {
                i.stok -= min.second;
                if (i.stok < 0) i.stok = 0;
            }
        }
    }
    saveStok(daftar); // Simpan setelah dikurangi
}

void terimaSembako(vector<Sembako>& daftar, const string& NIK) {
    akun users[MAX_USERS];
    int userCount = loadUsers(users);

    if (!checkStock(daftar, minimum)) {
        cout << "Stok tidak mencukupi.\n";
        return;
    }

    for (int i = 0; i < userCount; ++i) {
        if (users[i].NIK == NIK) {
            if (users[i].menerima) {
                cout << "Anda sudah menerima sembako.\n";
                return;
            }
            if (users[i].queue) {
                cout << "\n=== Daftar Sembako ===\n";
                cout << "Beras - 5kg\nTelur - 1kg\nMinyak - 2L\nGula - 1kg\nSusu - 2\nMie Instan - 10\n\n";

                kurangiStok(daftar, minimum);
                updateStatus(NIK);
                hapusAntrian();
            } else {
                cout << "Anda belum dipanggil! Silakan menunggu admin.\n";
            }
            return;
        }
    }

    cout << "NIK tidak ditemukan.\n";
}

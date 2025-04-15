#include <iostream>
#include <iomanip>
#include "functions/auth.h"
#include "functions/antrian.h"
#include "functions/stock.h"
#include "functions/distribusi.h"
#include "functions/cari.h"
#include "functions/helper.h"
#include <vector>

using namespace std;
vector<Sembako> daftar = {
    {"Beras", 100},
    {"Minyak Goreng", 50},
    {"Gula", 30},
    {"Susu", 20},
    {"Mie Instan", 200}
};

void userMenu(string user) {
    while(true) {
        system("CLS");
        string welcome = "Selamat datang " + user + "!";
        cout << "========================================" << endl;
        cout << "|                                      |" << endl;
        cout << "| " << left << setw(37) << welcome << "|\n";
        cout << "|                                      |" << endl;
        cout << "========================================" << endl;
        cout << "| No |           MENU UTAMA            |" << endl;
        cout << "========================================" << endl;
        cout << "| 1  | Tampilan antrian                |" << endl;
        cout << "| 2  | Ambil antrian                   |" << endl;
        cout << "| 3  | Terima sembako                  |" << endl;
        cout << "| 0  | Keluar                          |" << endl;
        cout << "========================================" << endl << endl;
        cout << "Pilih opsi (0-3): ";
        int pilihan;
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                lihatAntrian();
                system("pause");
                break;
            case 2:
                if (isPenerima(user)) { 
                    tambahAntrian(user);
                } else {
                    cout << "Maaf, Anda tidak memenuhi syarat untuk menerima sembako.\n";
                }
                system("pause");
                break;
            
            case 3:
                cout << "Terima sembako" << endl;
                break;
            case 0:
                cout << "Keluar dari program" << endl;
                return;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    }
}

void adminMenu() {
    while(true) {
        system("CLS"); 
        cout << "========================================" << endl;
        cout << "| No |           MENU ADMIN            |" << endl;
        cout << "========================================" << endl;
        cout << "| 1  | Lihat antrian                   |" << endl;
        cout << "| 2  | Hapus antrian                   |" << endl;
        cout << "| 3  | Cari data                       |" << endl;
        cout << "| 4  | Panggil Antrian                 |" << endl;
        cout << "| 5  | Lihat dan edit stok             |" << endl;
        cout << "| 6  | Riwayat distribusi              |" << endl;
        cout << "| 0  | Keluar                          |" << endl;
        cout << "========================================" << endl << endl;
        cout << "Pilih menu (0-5): ";
        int pilihan;
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                lihatAntrian();
                system("pause");
                break;
            case 2:
                hapusAntrian();
                system("pause");
                break;
            case 3:
                cariDataWarga();
                system("pause");
                break;
            case 4:
                panggilAntrian();
                system("pause");
                break;
            case 5:
                tampilanStok(daftar);
                editStok(daftar);
                system("pause");
                break;
            case 6:
                tampilkanRiwayatDistribusi();
                system("pause");
                break;
            case 0:
                cout << "Keluar dari program" << endl;
                return;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    }
}


int main() {
    string user;
    while (true) {
        system("CLS");
        user = menuLogin();
        if(user == "admin") {
            adminMenu();
        } else {
            userMenu(user);
        }
    }
    return 0;
}
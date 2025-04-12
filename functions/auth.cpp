#include <iostream>
#include <string>
#include "auth.h"
#include "helper.h"

using namespace std;

akun user;

void registerAkun() {
    system("CLS");
    cout << "Masukkan NIK: ";
    cin >> user.NIK;
    cout << "Masukkan Nama: ";
    cin >> user.nama;
    cout << "Masukkan Jenis Kelamin (L/P): ";
    cin >> user.jenisKelamin;
    cout << "Masukkan Umur: ";
    cin >> user.umur;
    cout << "Masukkan Password: ";
    cin >> user.password;

    saveUser(user);
}

string login() {
    system("CLS");
    string NIK;
    string password;
    cout << "=== LOGIN ===" << endl;
    cout << "Masukkan NIK: ";
    cin >> NIK;
    cout << "Masukkan Password: ";
    cin >> password;

    if(NIK == "admin" && password == "admin") {
        return "admin";
    }

    vector<akun> users = loadUsers();

    for (const akun& user : users) {
        if (user.NIK == NIK && user.password == password) {
            std::cout << "\nLogin berhasil!" << std::endl;
            return user.nama;
        }
    }
    cout << "\nLogin gagal! NIK atau password salah." << endl;
    return "null";
}

string menuLogin() {
    while(true) {
        system("CLS");
        cout << "========================================" << endl;
        cout << "| No |              LOGIN              |" << endl;
        cout << "========================================" << endl;
        cout << "| 1  | Login                           |" << endl;
        cout << "| 2  | Register                        |" << endl;
        cout << "| 0  | Keluar                          |" << endl;
        cout << "========================================" << endl << endl;
        cout << "Pilih menu (0-2): ";
        int pilihan;
        string user;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                user = login();
                if(user != "null") {
                    return user;
                } else {
                    continue;
                }
            case 2:
                registerAkun();
                break;
            case 0:
                exit(0);
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    }
}

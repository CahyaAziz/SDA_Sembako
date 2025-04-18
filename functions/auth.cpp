#include <iostream>
#include <string>
#include <limits>
#include "auth.h"
#include "helper.h"
#include "conio.h"

using namespace std;

akun user;
string inputPassword() {
    string password = "";
    char ch;

    while (true) {
        ch = _getch();

        if (ch == 13) {
            cout << endl;
            break;
        } else if (ch == 8) {
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password += ch;
            cout << '*';
        }
    }

    return password;
}

void registerAkun() {
    akun users[MAX_USERS];
    int userCount = loadUsers(users);

    system("CLS");
    while (true) {
        string NIK;
        bool dupe = false;

        cout << "Masukkan NIK: ";
        cin >> NIK;

        // Validate that NIK contains only digits
        bool isNumeric = true;
        for (char c : NIK) {
            if (!isdigit(c)) {
                isNumeric = false;
                break;
            }
        }

        if (!isNumeric) {
            cout << "NIK harus berupa angka. Silakan masukkan lagi." << endl;
            continue;
        }

        for (int i = 0; i < userCount; ++i) {
            if (users[i].NIK == NIK) {
                cout << endl << "NIK sudah terdaftar! Silakan gunakan NIK berbeda" << endl;
                dupe = true;
                break;
            }
        }
        if (dupe) {
            system("pause");
            return;
        }
        user.NIK = NIK;
        break;
    }

    cout << "Masukkan Nama: ";
    cin >> user.nama;

    while (true) {
        cout << "Masukkan Jenis Kelamin (L/P): ";
        cin >> user.jenisKelamin;
    
        char jk = tolower(user.jenisKelamin);
    
        if (jk == 'l' || jk == 'p') {
            break;
        } else {
            cout << "Input tidak valid. Silakan masukkan 'L' atau 'P'." << endl;
        }
    }
    
    while (true) {
        cout << "Masukkan Umur: ";
        cin >> user.umur;

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Input tidak valid. Masukkan angka." << endl;
            continue;
        }

        if (user.umur >= 40) {
            break;
        } else {
            cout << "Anda tidak memenuhi syarat." << endl;
        }
    }
    
    while (true) {
        cout << "Masukkan Password: ";
        user.password = inputPassword();
        if (user.password.empty()) {
            cout << "Password tidak boleh kosong. Silakan masukkan lagi. " << endl;
        } else {
            break;
        }
    }

    user.queue = false;
    user.menerima = false;

    saveUser(user);
}

string login() {
    system("CLS");
    string NIK, password;
    cout << "=== LOGIN ===" << endl;
    cout << "Masukkan NIK: ";
    cin >> NIK;
    cout << "Masukkan Password: ";
    password = inputPassword();


    if (NIK == "admin" && password == "admin") {
        return "admin";
    }

    akun users[MAX_USERS];
    int userCount = loadUsers(users);

    for (int i = 0; i < userCount; ++i) {
        if (users[i].NIK == NIK && users[i].password == password) {
            cout << "\nLogin berhasil!" << endl;
            system("pause");
            return users[i].NIK; // Return the user's NIK
        }
    }

    cout << "\nLogin gagal! NIK atau password salah." << endl;
    system("pause");
    return "null";
}

string menuLogin() {
    while (true) {
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
                if (user != "null") {
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

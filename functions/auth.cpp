#include <iostream>
#include <string>
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

        if (ch == 13) { // ENTER
            cout << endl;
            break;
        } else if (ch == 8) { // BACKSPACE
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

    while (true) {
        string NIK;
        bool dupe = false;

        system("CLS");
        cout << "Masukkan NIK: ";
        cin >> NIK;

        for (int i = 0; i < userCount; ++i) {
            if (users[i].NIK == NIK) {
                cout << endl << "Akun sudah ada!" << endl;
                dupe = true;
                break;
            }
        }
        if (dupe) {
            continue;
        }
        user.NIK = NIK;
        break;
    }

    cout << "Masukkan Nama: ";
    cin >> user.nama;

    while (true) {
        cout << "\nMasukkan Jenis Kelamin (L/P): ";
        cin >> user.jenisKelamin;
    
        // Ubah ke huruf kecil agar lebih fleksibel
        char jk = tolower(user.jenisKelamin);
    
        if (jk == 'l' || jk == 'p') {
            break;
        } else {
            cout << "Input tidak valid. Silakan masukkan 'L' atau 'P'.";
        }
    }
    
    while (true) {
        cout << "\nMasukkan Umur: ";
        cin >> user.umur;
    
        if (user.umur >= 40) {
            break;
        } else {
            cout << "Anda tidak memenuhi syarat.";
        }
    }
    


    
    cout << "\nMasukkan Password: ";
    user.password = inputPassword();

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

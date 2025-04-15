#ifndef AUTH_H
#define AUTH_H

#include <string>
using namespace std;

struct akun {
    string NIK;
    string nama;
    char jenisKelamin;
    int umur;
    string password;
    bool menerima;
};

void registerAkun();
string login();
string menuLogin();

#endif

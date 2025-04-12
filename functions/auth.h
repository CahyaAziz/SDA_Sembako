#ifndef AUTH_H
#define AUTH_H

#include <string>
using namespace std;

struct akun {
    std::string NIK;
    std::string nama;
    char jenisKelamin;
    int umur;
    std::string password;
    bool menerima;
};

extern akun user;

void registerAkun();
string login();
string menuLogin();

#endif
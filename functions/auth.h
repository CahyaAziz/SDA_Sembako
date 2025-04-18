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
    bool queue;     // Indicates if the user is in the queue
    bool menerima;  // Indicates if the user has received sembako
};

void registerAkun();
string login();
string menuLogin();

#endif

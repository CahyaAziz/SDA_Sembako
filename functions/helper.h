#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <string>
#include "auth.h"
#include "stock.h"
using namespace std;

#define MAX_USERS 50

void saveUser(const akun& user, const string& filename = "users.csv");
int loadUsers(akun users[], const string& filename = "users.csv");
vector<Sembako> loadSembako(const string& filename = "stock.csv");
bool isPenerima(const string& nama);
void updateStatus(const string& NIK, bool queueState); // Updated declaration
bool isUserInQueue(const string& NIK);
void saveStok(const std::vector<Sembako>& daftar);
// std::vector<Sembako> loadStokFromCSV();

#endif

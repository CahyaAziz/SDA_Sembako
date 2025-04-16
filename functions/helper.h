#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <string>
#include "auth.h"
#include "stock.h"
using namespace std;

void saveUser(const akun& user, const string& filename = "users.csv");
vector<akun> loadUsers(const string& filename = "users.csv");
vector<Sembako> loadSembako(const string& filename = "stock.csv");
bool isPenerima(const string& nama);
void updateStatus(const string& nama);
bool isUserInQueue(const string& NIK);
void saveStokToCSV(const std::vector<Sembako>& daftar);
std::vector<Sembako> loadStokFromCSV();


#endif

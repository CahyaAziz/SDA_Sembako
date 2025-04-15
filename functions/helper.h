#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <string>
#include "auth.h"

void saveUser(const akun& user, const std::string& filename = "users.csv");
std::vector<akun> loadUsers(const std::string& filename = "users.csv");
bool isPenerima(const std::string& nama);
void updateStatus(const std::string& nama);

#endif

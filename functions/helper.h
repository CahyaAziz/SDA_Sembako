#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <vector>
#include "auth.h"

void saveUser(const akun& user, const string& filename = "users.csv");
vector<akun> loadUsers(const string& filename = "users.csv");

#endif
#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>
using namespace std;

struct Sembako {
    string nama;
    int stok;
};

void tampilanStok(const vector<Sembako>& daftar);
void editStok(vector<Sembako>& daftar);

#endif

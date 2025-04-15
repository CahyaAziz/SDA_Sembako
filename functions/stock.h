#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>
using namespace std;

struct Sembako {
    string nama;
    int stok;
};

extern vector<pair<string, int>> minimum; // Declare as extern

void tampilanStok(const vector<Sembako>& daftar);
void editStok(vector<Sembako>& daftar);
bool checkStock(const vector<Sembako>& daftar, const vector<pair<string, int>>& minimums);
void terimaSembako(const vector<Sembako>& daftar, const string& NIK);

#endif
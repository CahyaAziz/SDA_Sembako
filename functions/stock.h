#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>
#include <utility> // untuk std::pair

struct Sembako {
    std::string nama;
    int stok;
};

// Deklarasi variabel minimum dari stock.cpp
extern std::vector<std::pair<std::string, int>> minimum;

// Fungsi-fungsi terkait stok sembako
void tampilanStok(const std::vector<Sembako>& daftar);
void editStok(std::vector<Sembako>& daftar);
bool checkStock(const std::vector<Sembako>& daftar, const std::vector<std::pair<std::string, int>>& minimums);
void terimaSembako(std::vector<Sembako>& daftar, const std::string& NIK); // <- diperbaiki agar daftar bisa berubah stoknya

#endif // STOCK_H

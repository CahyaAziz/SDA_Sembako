#ifndef STOK_H
#define STOK_H

#include <iostream>
#include <vector>
#include <string>

struct Sembako {
    std::string nama;
    int stok;
};


void tampilanStok(const std::vector<Sembako>& daftar);
void editStok(std::vector<Sembako>& daftar);

#endif

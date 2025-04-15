#ifndef ANTRIAN_H
#define ANTRIAN_H

#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

extern Node* head;

bool sudahAdaDalamAntrian(string nama);
int hitungJumlahAntrian();
void tambahAntrian(string nama);
void lihatAntrian();
void hapusAntrian();
void panggilAntrian(); // ← Tambahkan ini agar bisa digunakan di main.cpp

#endif

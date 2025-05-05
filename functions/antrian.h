#ifndef ANTRIAN_H
#define ANTRIAN_H

#include <string>
using namespace std;

struct Node {
    string NIK;
    string nama;
    Node* next;
};

extern Node* head;

bool sudahAdaDalamAntrian(string NIK);
int hitungJumlahAntrian();
void tambahAntrian(string NIK, string nama);
void lihatAntrian();
void hapusAntrian();
void lewatiAntrian();
void panggilAntrian();

#endif
#ifndef ANTRIAN_H
#define ANTRIAN_H

#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

extern Node* head;

void tambahAntrian(string nama);
void lihatAntrian();
void hapusAntrian();

#endif

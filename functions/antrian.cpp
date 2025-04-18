#include "antrian.h"
#include "helper.h"
#include <iostream>
using namespace std;

Node* head = nullptr;

bool sudahAdaDalamAntrian(string NIK) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->NIK == NIK) {
            return true; // NIK sudah ada di antrian
        }
        temp = temp->next;
    }
    return false;
}

int hitungJumlahAntrian() {
    int jumlah = 0;
    Node* temp = head;
    while (temp != nullptr) {
        jumlah++;
        temp = temp->next;
    }
    return jumlah;
}

void tambahAntrian(string NIK, string nama) {
    if (sudahAdaDalamAntrian(NIK)) {
        cout << "Anda telah mengambil antrian. Terima kasih.\n";
        return;
    }

    Node* baru = new Node{NIK, nama, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = baru;
    }

    int noAntrian = hitungJumlahAntrian(); // Hitung setelah ditambahkan
    cout << "Antrian berhasil ditambahkan!\n";
    cout << "Nama: " << nama << "\n";
    cout << "Nomor Antrian Anda: " << noAntrian << endl;
}

void lihatAntrian() {
    if (head == nullptr) {
        cout << "Belum ada antrian." << endl;
        return;
    }
    cout << "Daftar Antrian:\n";
    Node* temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->nama << " (NIK: " << temp->NIK << ")" << endl;
        temp = temp->next;
    }
}

void hapusAntrian() {
    updateStatus(head->NIK, false);
    if (head == nullptr) {
        cout << "Antrian kosong." << endl;
        return;
    }
    Node* hapus = head;
    cout << "Menghapus antrian: " << hapus->nama << endl;
    head = head->next;
    delete hapus;
}

void lewatiAntrian() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* lewati = head;
    head = head->next;
    lewati->next = nullptr;

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = lewati;
}

void panggilAntrian() {
    while (head != nullptr) {
        if (isUserInQueue(head->NIK)) {
            cout << "\nUser atas nama: " << head->nama << " (NIK: " << head->NIK << ") belum mengambil sembako." << endl;
            cout << "1. Lewati antrian" << endl;
            cout << "2. Kembali ke menu admin" << endl;
            cout << "Pilihan: ";
            int opsi;
            cin >> opsi;

            if (opsi == 1) {
                cout << "Antrian atas nama " << head->nama << " dilewati." << endl;
                updateStatus(head->NIK, false);
                lewatiAntrian();
                continue;
            } else if (opsi == 2) {
                return;
            } else {
                cout << "Pilihan tidak valid!" << endl;
                continue;
            }
        }

        cout << "\nMemanggil antrian atas nama: " << head->nama << " (NIK: " << head->NIK << ")" << endl;
        cout << "Apakah warga hadir dan menerima sembako?" << endl;
        cout << "1. Ya" << endl;
        cout << "2. Tidak, lewati" << endl;
        cout << "3. Keluar dari menu panggil antrian" << endl;
        cout << "Pilihan: ";
        int opsi;
        cin >> opsi;

        if (opsi == 1) {
            updateStatus(head->NIK, true); 
            break;
        } else if (opsi == 2) {
            cout << "Antrian atas nama " << head->nama << " dilewati." << endl;
            lewatiAntrian();
            break;
        } else {
            break;
        }
    }

    if (head == nullptr) {
        cout << "Antrian telah habis.\n";
    }
}

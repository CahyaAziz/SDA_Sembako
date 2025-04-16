#include "cari.h"
#include "auth.h"
#include "helper.h"
#include "antrian.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

extern Node* head;

void cariDataWarga() {
    system("CLS");
    akun users[MAX_USERS];
    int userCount = loadUsers(users);
    string input;
    bool ditemukan = false;

    cout << "=== Cari Data Warga ===\n";
    cout << "Masukkan NIK: ";
    cin.ignore(); // Clear buffer
    getline(cin, input);

    for (int i = 0; i < userCount; ++i) {
        if (users[i].NIK == input) {
            ditemukan = true;

            cout << "\nData Ditemukan:\n";
            cout << "NIK           : " << users[i].NIK << endl;
            cout << "Nama          : " << users[i].nama << endl;
            cout << "Jenis Kelamin : " << users[i].jenisKelamin << endl;
            cout << "Umur          : " << users[i].umur << endl;

            // Cek status antrian
            Node* temp = head;
            int posisi = 1;
            bool dalamAntrian = false;
            while (temp != nullptr) {
                if (temp->NIK == users[i].NIK) {
                    dalamAntrian = true;
                    break;
                }
                posisi++;
                temp = temp->next;
            }

            if (dalamAntrian) {
                cout << "Status        : Belum menerima sembako\n";
                cout << "Nomor Antrian : " << posisi << endl;

                // Opsi hapus
                char hapus;
                cout << "\nHapus dari antrian? (y/n): ";
                cin >> hapus;
                if (tolower(hapus) == 'y') {
                    if (head->NIK == users[i].NIK) {
                        hapusAntrian();
                    } else {
                        Node* prev = head;
                        Node* curr = head->next;
                        while (curr != nullptr && curr->NIK != users[i].NIK) {
                            prev = curr;
                            curr = curr->next;
                        }
                        if (curr != nullptr) {
                            prev->next = curr->next;
                            delete curr;
                            cout << "Berhasil dihapus dari antrian.\n";
                        }
                    }
                }
            } else {
                cout << "Status        : " << (users[i].menerima ? "Sudah menerima sembako" : "Belum menerima sembako") << endl;
            }

            break;
        }
    }

    if (!ditemukan) {
        cout << "\nAkun tidak ditemukan." << endl;
    }

    cout << endl;
}
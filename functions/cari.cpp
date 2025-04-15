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
    vector<akun> users = loadUsers();
    string input;
    bool ditemukan = false;

    cout << "=== Cari Data Warga ===\n";
    cout << "Masukkan NIK atau Nama: ";
    cin.ignore(); // Clear buffer
    getline(cin, input);

    for (const akun& u : users) {
        if (u.NIK == input || u.nama == input) {
            ditemukan = true;

            cout << "\nData Ditemukan:\n";
            cout << "NIK           : " << u.NIK << endl;
            cout << "Nama          : " << u.nama << endl;
            cout << "Jenis Kelamin : " << u.jenisKelamin << endl;
            cout << "Umur          : " << u.umur << endl;

            // Cek status antrian
            Node* temp = head;
            int posisi = 1;
            bool dalamAntrian = false;
            while (temp != nullptr) {
                if (temp->nama == u.nama) {
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
                    if (head->nama == u.nama) {
                        hapusAntrian();
                    } else {
                        Node* prev = head;
                        Node* curr = head->next;
                        while (curr != nullptr && curr->nama != u.nama) {
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
                cout << "Status        : Sudah menerima sembako atau belum mengambil antrian\n";
            }

            break;
        }
    }

    if (!ditemukan) {
        cout << "\nAkun tidak ditemukan." << endl;
    }

    cout << endl;
    system("pause");
}

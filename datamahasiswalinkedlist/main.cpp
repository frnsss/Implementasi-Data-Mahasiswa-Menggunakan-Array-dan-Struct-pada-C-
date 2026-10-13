#include <iostream>
#include <string>
#include <limits>
#include "Mahasiswa.h"

using namespace std;

int hitungJumlah(Mahasiswa *head) {
    int jumlah = 0;

    while (head != nullptr) {
        jumlah++;
        head = head->next;
    }

    return jumlah;
}

Mahasiswa* cariMahasiswa(Mahasiswa *head, string nim) {
    while (head != nullptr) {
        if (head->nim == nim)
            return head;

        head = head->next;
    }

    return nullptr;
}

void tampilkan(Mahasiswa *mhs) {
    cout << "Nama: " << mhs->nama << endl;
    cout << "NIM: " << mhs->nim << endl;
    cout << "Persentase Absen: "
         << mhs->percentageAbsen << "%" << endl;
}

int main() {
    Mahasiswa *head = nullptr;
    Mahasiswa *tail = nullptr;

    // Input 40 mahasiswa
    for (int i = 0; i < 40; i++) {
        Mahasiswa *baru = new Mahasiswa;

        cout << "\n=== Mahasiswa ke-" << i + 1 << " ===" << endl;

        cout << "Nama: ";
        getline(cin, baru->nama);

        cout << "NIM: ";
        getline(cin, baru->nim);

        cout << "Persentase Absen: ";
        cin >> baru->percentageAbsen;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        baru->next = nullptr;

        if (head == nullptr) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            tail = baru;
        }
    }

    cout << "\nJumlah mahasiswa sebelum update: "
         << hitungJumlah(head) << endl;

    // Cari mahasiswa
    string nimCari;

    cout << "\nMasukkan NIM yang dicari: ";
    getline(cin, nimCari);

    Mahasiswa *hasil = cariMahasiswa(head, nimCari);

    if (hasil != nullptr) {
        cout << "\n=== DATA DITEMUKAN ===" << endl;
        tampilkan(hasil);

        // Update data
        cout << "\n=== UPDATE DATA ===" << endl;

        cout << "Nama baru: ";
        getline(cin, hasil->nama);

        cout << "NIM baru: ";
        getline(cin, hasil->nim);

        cout << "Persentase Absen baru: ";
        cin >> hasil->percentageAbsen;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n=== HASIL UPDATE ===" << endl;
        tampilkan(hasil);
    } else {
        cout << "\nData tidak ditemukan." << endl;
    }

    cout << "\nJumlah mahasiswa setelah update: "
         << hitungJumlah(head) << endl;

    // Tampilkan semua data
    cout << "\n===== DATA SELURUH MAHASISWA =====" << endl;

    Mahasiswa *ptr = head;
    int nomor = 1;

    while (ptr != nullptr) {
        cout << "\nMahasiswa ke-" << nomor++ << endl;
        tampilkan(ptr);
        ptr = ptr->next;
    }

    // Hapus linked list
    while (head != nullptr) {
        Mahasiswa *hapus = head;
        head = head->next;
        delete hapus;
    }

    return 0;
}

#include <iostream>
#include <string>
#include "Mahasiswa.h"

using namespace std;

Mahasiswa* cariMahasiswa(Mahasiswa mhs[], int jumlah, string nim) {
    for (int i = 0; i < jumlah; i++) {
        if (mhs[i].nim == nim)
            return &mhs[i];
    }
    return nullptr;
}

void tampilkan(Mahasiswa *mhs) {
    cout << "Nama: " << mhs->nama << endl;
    cout << "NIM: " << mhs->nim << endl;
    cout << "Persentase Absen: " << mhs->percentageAbsen << "%" << endl;
}

int main() {
    Mahasiswa mhs[40];

    // Input 40 mahasiswa
    for (int i = 0; i < 40; i++) {
        cout << "\n=== Mahasiswa ke-" << i + 1 << " ===" << endl;

        cout << "Nama: ";
        getline(cin, mhs[i].nama);

        cout << "NIM: ";
        getline(cin, mhs[i].nim);

        cout << "Persentase Absen: ";
        cin >> mhs[i].percentageAbsen;

        // Mengabaikan sisa karakter di baris tersebut (termasuk tanda % atau newline)
        cin.ignore(1000, '\n');
    }

    cout << "\nJumlah mahasiswa sebelum update: 40" << endl;

    // Pencarian
    string nimCari;
    cout << "\nMasukkan NIM yang dicari: ";
    getline(cin, nimCari);

    Mahasiswa *hasil = cariMahasiswa(mhs, 40, nimCari);

    if (hasil != nullptr) {
        cout << "\n=== DATA DITEMUKAN ===" << endl;
        tampilkan(hasil);

        // Update
        cout << "\n=== UPDATE DATA ===" << endl;

        cout << "Nama baru: ";
        getline(cin, hasil->nama);

        cout << "NIM baru: ";
        getline(cin, hasil->nim);

        cout << "Persentase Absen baru: ";
        cin >> hasil->percentageAbsen;
        cin.ignore(1000, '\n');

        cout << "\n=== HASIL UPDATE ===" << endl;
        tampilkan(hasil);
    } else {
        cout << "\nData tidak ditemukan." << endl;
    }

    cout << "\nJumlah mahasiswa setelah update: 40" << endl;

    // Tampilkan semua data
    cout << "\n===== DATA SELURUH MAHASISWA =====" << endl;

    for (int i = 0; i < 40; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        tampilkan(&mhs[i]);
    }

    // Tahanan agar terminal Code::Blocks tidak langsung close di akhir
    cout << "\nTekan Enter untuk keluar...";
    cin.get();

    return 0;
}

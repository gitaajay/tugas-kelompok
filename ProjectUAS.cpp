#include <iostream>
#include <string>

using namespace std;

struct Transaksi {
    string jenis;
    string nama;
    string kategori;
    long long nominal;
};

const int MAX_TRANSAKSI = 100;

void tambahPemasukan(Transaksi daftarTransaksi[], int &jumlahTransaksi) {
    char ulangInput;
    do {
        if (jumlahTransaksi >= MAX_TRANSAKSI) {
            cout << "Kapasitas penyimpanan transaksi sudah penuh!\n";
            break;
        }

        Transaksi baru;
        baru.jenis = "Pemasukan";
        baru.kategori = "-";

        cout << "\nMasukkan nama/sumber pemasukan: ";
        cin.ignore();
        getline(cin, baru.nama);

        cout << "Masukkan nominal pemasukan: Rp";
        cin >> baru.nominal;

        if (baru.nominal > 0) {
            daftarTransaksi[jumlahTransaksi] = baru;
            jumlahTransaksi++;
            cout << "Pemasukan berhasil ditambahkan.\n";
        } else {
            cout << "Nominal harus lebih dari 0.\n";
        }

        cout << "Ingin menginput pemasukan lagi? (y/n): ";
        cin >> ulangInput;
    } while (ulangInput == 'y' || ulangInput == 'Y');
}

void tambahPengeluaran(Transaksi daftarTransaksi[], int &jumlahTransaksi) {
    char ulangInput;
    do {
        if (jumlahTransaksi >= MAX_TRANSAKSI) {
            cout << "Kapasitas penyimpanan transaksi sudah penuh!\n";
            break;
        }

        Transaksi baru;
        baru.jenis = "Pengeluaran";
        int pilihanKategori;

        cout << "\nMasukkan nama pengeluaran: ";
        cin.ignore();
        getline(cin, baru.nama);

        cout << "Pilih Kategori Pengeluaran:\n";
        cout << "1. Kebutuhan\n";
        cout << "2. Keinginan\n";
        cout << "Masukkan pilihan kategori (1-2): ";
        cin >> pilihanKategori;

        switch (pilihanKategori) {
            case 1:
                baru.kategori = "Kebutuhan";
                break;
            case 2:
                baru.kategori = "Keinginan";
                break;
            default:
                baru.kategori = "Kebutuhan";
                cout << "Pilihan tidak valid, otomatis masuk ke 'Kebutuhan'.\n";
                break;
        }

        cout << "Masukkan nominal pengeluaran: Rp";
        cin >> baru.nominal;

        if (baru.nominal > 0) {
            daftarTransaksi[jumlahTransaksi] = baru;
            jumlahTransaksi++;
            cout << "Pengeluaran [" << baru.kategori << "] berhasil disimpan.\n";
        } else {
            cout << "Nominal harus lebih dari 0.\n";
        }

        cout << "Ingin menginput pengeluaran lagi? (y/n): ";
        cin >> ulangInput;
    } while (ulangInput == 'y' || ulangInput == 'Y');
}


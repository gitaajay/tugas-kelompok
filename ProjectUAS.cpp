#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Transaksi {
    string jenis;
    string nama;
    string kategori;
    long long nominal;
};

const int MAX_TRANSAKSI = 100;

void tampilkanRiwayat(Transaksi daftarTransaksi[], int jumlahTransaksi) {
    cout << "\n==================== RIWAYAT TRANSAKSI ====================\n";
    
    if (jumlahTransaksi == 0) {
        cout << "Belum ada data transaksi yang tercatat.\n";
        return;
    }

    cout << left << setw(5)  << "No"
         << left << setw(14) << "Jenis"
         << left << setw(22) << "Nama Transaksi"
         << left << setw(13) << "Kategori"
         << left << setw(15) << "Nominal" << "\n";
    cout << "-------------------------------------------------------------------\n";

    for (int i = 0; i < jumlahTransaksi; i++) {
        cout << left << setw(5)  << (i + 1)
             << left << setw(14) << daftarTransaksi[i].jenis
             << left << setw(22) << daftarTransaksi[i].nama
             << left << setw(13) << daftarTransaksi[i].kategori
             << "Rp" << daftarTransaksi[i].nominal << "\n";
    }
    cout << "===================================================================\n";
}


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

int main() {
    Transaksi daftarTransaksi[MAX_TRANSAKSI];
    int jumlahTransaksi = 0;
    int pilihanMenu = 0;

    do {
        cout << "\n================ MENU UTAMA ================\n";
        cout << "1. Input Pemasukan\n";
        cout << "2. Input Pengeluaran\n";
        cout << "3. Lihat Riwayat Transaksi (Bagian Anak 2)\n";
        cout << "4. Ringkasan Saldo (Bagian Anak 3)\n";
        cout << "5. Urutkan Pengeluaran Terbesar (Bagian Anak 3)\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1-6): ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1:
                tambahPemasukan(daftarTransaksi, jumlahTransaksi);
                break;
            case 2:
                tambahPengeluaran(daftarTransaksi, jumlahTransaksi);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "Pilihan menu tidak valid. Silakan pilih 1-6.\n";
                break;
        }

    } while (pilihanMenu != 6);

    return 0;
}

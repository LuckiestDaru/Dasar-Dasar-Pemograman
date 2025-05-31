#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct buku {
    string judul;
    string pengarang;
};

vector<buku> bku;

void bersih() {
    system("cls");
}


void tambahBuku() {
    char lanjut;
    do {
        buku bukuPles;
        cin.ignore(1000, '\n');
        bersih();
        cout << "Masukkan judul buku: ";
        getline(cin, bukuPles.judul);
        cout << "Masukkan nama pengarang: ";
        getline(cin, bukuPles.pengarang);

        bku.push_back(bukuPles);
        cout << "Buku berhasil ditambahkan!" << endl;

        cout << "Ingin menambah buku lagi? (y/n): ";
        cin >> lanjut;

        while (lanjut != 'y' && lanjut != 'Y' && lanjut != 'n' && lanjut != 'N') {
            cout << "Masukkan y atau n!!" << endl;
            cout << "Tekan untuk mengulangi" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin.get();
            bersih();

            cout << "Ingin menambah buku lagi? (y/n): ";
            cin >> lanjut;
        }
        if (lanjut == 'n' || lanjut == 'N') {
            char kembali;
            cout << "Apakah ingin kembali ke menu utama? y/n" << endl;
            cin >> kembali;
            while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
                cout << "Masukkan y atau n!!" << endl;
                cout << "Tekan untuk mengulangi" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin.get();
                bersih();

                cout << "Apakah ingin kembali ke menu utama? y/n" << endl;
                cin >> kembali;
            }
            if (kembali == 'n' || kembali == 'N') {
                cout << "Terimakasih telah mengunakan program ini" << endl;
                exit(0);
            }
            return;
        }
    } while (lanjut == 'y' || lanjut == 'Y');
}

void bukutabuti() {
    cout << "===Daftar Buku===" << endl;
    for (size_t i = 0; i < bku.size(); i++) {
        cout << "Buku Ke: " << i + 1 << endl;
        cout << "Judul Buku    : " << bku[i].judul << endl;
        cout << "Nama Pengarang: " << bku[i].pengarang << endl << endl;
    }
}

void tampilkanBuku() {
    char lanjut;
    do {
        if (bku.empty()) {
            cout << "Tidak ada buku dalam perpustakaan." << endl;
            cout << "\nTekan Enter untuk kembali ke menu utama...";
            cin.ignore(1000, '\n');
            cin.get();
            return;
        }

        bersih();
        bukutabuti();

        cout << "Apakah ingin menampilkan Buku lagih?? y/n" << endl;
        cin >> lanjut;

        while (lanjut != 'y' && lanjut != 'Y' && lanjut != 'n' && lanjut != 'N') {
            cout << "INVALID!!!" << endl;
            cout << "Masukkan pilihan HANYA y dan n!!!" << endl;
            cout << "Tekan untuk melanjutkan..." << endl << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin.get();

            bersih();
            bukutabuti();
            cout << "Apakah ingin menampilkan buku lagi? y/n: " << endl;
            cin >> lanjut;
        }
        if (lanjut == 'n' || lanjut == 'N') {
            char kembali;
            cout << "Apakah ingin kembali ke menu utama? y/n" << endl;
            cin >> kembali;
            while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
                cout << "INPALID!!!" << endl;
                cout << "Masukkan pilihan HANYA y dan n!!!" << endl;
                cout << "Tekan untuk melanjutkan..." << endl << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin.get();
                bersih();
                cout << "Apakah ingin kembali ke menu utama? y/n" << endl;
                cin >> kembali;
            }
            if (kembali == 'n' || kembali == 'N') {
                cout << "Terimakasih telah mengunakan program ini..." << endl;
                exit(0);
            }
        }
    } while (lanjut == 'y' || lanjut == 'Y');
}

void ubahBuku() {
    char lanjut;
    do {
        if (bku.empty()) {
            bersih();
            cout << "Tidak ada buku disini.." << endl;
            cout << "Tekan enter untuk kembali ke menu..." << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            cin.get();
            return;
        }

        bukutabuti();

        cin.ignore(1000, '\n');
        string judulCari;
        cout << "Masukkan judul buku yang ingin diubah: ";
        getline(cin, judulCari);

        auto it = find_if(bku.begin(), bku.end(), [&judulCari](const buku& b) {
            return b.judul == judulCari;
            });

        if (it == bku.end()) {
            cout << "Judul buku tidak ada!!" << endl;
        }
        else {
            bersih();
            cout << "Masukkan judul baru (kosongkan jika tidak ingin mengubah): ";
            string newjudul;
            getline(cin, newjudul);
            if (!newjudul.empty()) it->judul = newjudul;

            cout << "Masukkan nama pengarang baru (kosongkan jika tidak ingin mengubah): ";
            string newpengarang;
            getline(cin, newpengarang);
            if (!newpengarang.empty()) it->pengarang = newpengarang;

            cout << "Buku berhasil diubah!" << endl;
        }

        cout << "Ingin mengubah buku lagi? (y/n): ";
        cin >> lanjut;

        while (lanjut != 'y' && lanjut != 'Y' && lanjut != 'n' && lanjut != 'N') {
            cout << "INPUT INVALIDD!!!" << endl;
            cout << "\nMasukkan y atau n!!" << endl;
            cout << "Tekan enter...." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin.get();
            bersih();

            cout << "Ingin mengubah buku lagi? (y/n): ";
            cin >> lanjut;
        }
        if (lanjut == 'n' || lanjut == 'N') {
            char kembali;
            cout << "Apakah ingin kembali ke menu utama? y/n" << endl;
            cin >> kembali;
            while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
                cout << "INPALID!!!" << endl;
                cout << "Masukkan pilihan HANYA y dan n!!!" << endl;
                cout << "Tekan untuk melanjutkan..." << endl << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin.get();
                bersih();
                cout << "Apakah ingin kembali ke menu utama? y/n" << endl;
                cin >> kembali;
            }
            if (kembali == 'n' || kembali == 'N') {
                cout << "Terimakasih telah mengunakan program ini..." << endl;
                exit(0);
            }
        }

    } while (lanjut == 'y' || lanjut == 'Y');
}

void hapusBuku() {
    char lanjut;
    do {
        bersih();
        bukutabuti();
        if (bku.empty()) {
            cout << "Gada buku cok!" << endl;
            cout << "Tekan enter..." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin.get();
            return;
        }

        cin.ignore(1000, '\n');
        string judulHapus;
        cout << "Masukkan judul buku yang akan dihapus: ";
        getline(cin, judulHapus);

        auto it = find_if(bku.begin(), bku.end(), [&judulHapus](const buku& b) {
            return b.judul == judulHapus;
            });

        if (it == bku.end()) {
            cout << "Judul buku tidak ada!!" << endl;
        }
        else {
            bku.erase(it);
            cout << "Buku berhasil dihapus!" << endl;
        }

        cout << "Ingin menghapus buku lagi? (y/n): ";
        cin >> lanjut;

        while(lanjut != 'y' && lanjut != 'Y' && lanjut != 'n' && lanjut != 'N') {
            cout << "INPALITT!!!!" << endl;
            cout << "Hanya mmasukkan y atau n!" << endl;
            cout << "Tekan enter untuk melanjutkan" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin.get();
            bersih();

            cout << "Apakah ingin menghapus buku lagi? y/n" << endl;
            cin >> lanjut;
        }
        if (lanjut == 'n' || lanjut == 'N') {
            char kembali;
            cout << "Apakah ingin kembali ke menu utama? y/n" << endl;
            cin >> kembali;
            while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
                cout << "INPALID!!!" << endl;
                cout << "Masukkan pilihan HANYA y dan n!!!" << endl;
                cout << "Tekan untuk melanjutkan..." << endl << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin.get();
                bersih();
                cout << "Apakah ingin kembali ke menu utama? y/n" << endl;
                cin >> kembali;
            }
            if (kembali == 'n' || kembali == 'N') {
                cout << "Terimakasih telah mengunakan program ini..." << endl;
                exit(0);
            }
        }
    } while (lanjut == 'y' || lanjut == 'Y');
}

int menu() {
    int menyu;

    bersih();
    cout << "\n===MENU PERPUSTAKAAN===" << endl;
    cout << "1. Tambah Buku" << endl;
    cout << "2. Tampilkan Buku" << endl;
    cout << "3. Ubah Buku" << endl;
    cout << "4. Hapus Buku" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilihan : ";

    cin >> menyu;
    return menyu;
}

int main() {
    int pilihan;
    do {
        pilihan = menu();
        while (!pilihan) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "\n Input salah harus angka" << endl;

            cout << "Tekan untuk mengulangi...";
            cin.get();
            system("cls");
            return main();
        }
        switch (pilihan) {
        case 1:
            tambahBuku();
            break;
        case 2:
            tampilkanBuku();
            break;
        case 3:
            ubahBuku();
            break;
        case 4:
            hapusBuku();
            break;
        case 5:
            cout << "Terima kasih telah menggunakan program perpustakaan!" << endl;
            return 0;
        default:
            cout << "Pilihan hanya tersedia 1-5" << endl;
            cout << "Tekan Enter untuk kembali ke menu utama...";
            cin.ignore(1000, '\n');
            cin.get();
            break;
        }
    } while (true);

    return 0;
}
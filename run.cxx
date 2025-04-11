#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cctype>

using namespace std;

string generateRandomCode(int length) {
    const string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string code;
    srand(time(0));
    
    for(int i = 0; i < length; i++) {
        code += CHARACTERS[rand() % CHARACTERS.size()];
    }
    return code;
}

int main() {
    string nama, film, tempat, kodeTiket;
    const int HARGA_TIKET = 25000;
    int jumlahOrang, totalHarga, pembayaran, kembalian;
    char tempatDuduk;
    string kodeFilm, inputCode;

    // Input nama
    cout << "\n=== PEMESANAN TIKET BIOSKOP ONLINE ===\n";
    cout << "1. Masukkan Nama: ";
    getline(cin, nama);

    // Pilih film
    do {
        cout << "\n2. Pilih Film:\n";
        cout << "   - Horror (HT)\n";
        cout << "   - Komedi (KD)\n";
        cout << "   - Romantis (RA)\n";
        cout << "   Masukkan kode film: ";
        cin >> kodeFilm;

        for (auto& c : kodeFilm) c = toupper(c);
        
        if(kodeFilm == "HT") film = "Horror";
        else if(kodeFilm == "KD") film = "Komedi";
        else if(kodeFilm == "RA") film = "Romantis";
        else cout << "Kode tidak valid!\n";
        
    } while(kodeFilm != "HT" && kodeFilm != "KD" && kodeFilm != "RA");

    // Pilih tempat duduk
    do {
        cout << "\n3. Pilih Tempat Duduk (A/B/C/D): ";
        cin >> tempatDuduk;
        tempatDuduk = toupper(tempatDuduk);
    } while(tempatDuduk < 'A' || tempatDuduk > 'D');
    tempat = "Kursi " + string(1, tempatDuduk);

    // Input jumlah orang
    cout << "\n4. Masukkan Jumlah Orang: ";
    cin >> jumlahOrang;
    
    // Hitung total harga
    totalHarga = HARGA_TIKET * jumlahOrang;
    
    // Sistem pembayaran
    do {
        cout << "\n5. Masukkan Pembayaran (Minimal Rp" << totalHarga << "): Rp";
        while(!(cin >> pembayaran)) {
            cout << "Input tidak valid! Masukkan angka: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        if(pembayaran < totalHarga) {
            cout << "Pembayaran kurang! Kurang Rp" << (totalHarga - pembayaran) << endl;
        }
    } while(pembayaran < totalHarga);
    
    // Hitung kembalian
    kembalian = pembayaran - totalHarga;
    
    cout << "\n=== RINCIAN PEMBAYARAN ===";
    cout << "\nHarga Tiket    : Rp" << HARGA_TIKET << "/orang";
    cout << "\nJumlah Orang   : " << jumlahOrang;
    cout << "\nTotal Harga    : Rp" << totalHarga;
    cout << "\nPembayaran     : Rp" << pembayaran;
    cout << "\nKembalian      : Rp" << kembalian << endl;

    // Generate kode tiket
    kodeTiket = generateRandomCode(6);
    cout << "\n=== KODE TIKET ANDA ===";
    cout << "\nSilakan salin kode berikut: " << kodeTiket;

    // Validasi kode tiket
    do {
        cout << "\n\n6. Masukkan Kode Tiket (huruf kapital): ";
        cin >> inputCode;
        
        for(auto& c : inputCode) c = toupper(c);
        
        if(inputCode != kodeTiket) {
            cout << "Kode salah! Silakan coba lagi!";
        }
    } while(inputCode != kodeTiket);

    // Simulasi penayangan film
    cout << "\n\n=== FILM SEDANG BERLANGSUNG ===";
    cout << "\nTekan Enter untuk keluar dari bioskop...";
    cin.ignore();
    cin.get();

    cout << "\nTerima kasih telah menonton! Program selesai.\n";
    return 0;
}
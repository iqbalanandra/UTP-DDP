#include <iostream>
#include <stdlib.h>
using namespace std;

void signup(void); // Prototype agar void setelah main dapat dijalankan(Sudah di deklarasikan)
void login(void);  // Prototype juga
// PROTOTYPE DIGUNAKAN APABILA VOID DIGUNAKAN SETELAH MAIN
int main()
{

    while (true) // Menu UTAMA akan dimunculkan kembali terus menerus karena nilainya selalu true(selalu diulang)
    {
        cout << " ________________________\n";
        cout << "|                        |\n|     SELAMAT DATANG     |" << endl;
        cout << "|________________________|"<<endl;
        cout << "Silahkan pilih menu berikut:\n";
        cout << "1. Login" << endl;
        cout << "2. Sign-up" << endl;
        cout << "3. Exit Program" << endl;
        int pilihan;
        cin >> pilihan;
        

        switch (pilihan)
        {
        case 1:      // Ketik 1 untuk ke menu LOGIN
            login(); // Menjalankan fungsi login
            break;
        case 2:       // Ketik 2 untuk ke menu SIGN-UP
            signup(); // menjalankan fungsi sign-up
            break;
        case 3: // Ketik 3 untuk mengakhiri program
            return 0;
        default: // Apabila inputan tidak ada di salah satu dari yang tertera
            cout << "\nPilih Salah Satu dari YANG TERTERA!!\n\n";
        }
    }
}
string apassword[100], auser[100];
int akun = 0;// counter jumlah akun yang terdaftar
void signup(void)
{

    cout << "Buat username \t: ";
    cin >> auser[akun]; // Menyimpan user akun ke variabel tersebut
    cout << "Buat password \t: ";
    cin >> apassword[akun];// Menyimpan password tersebut ke variabel tersebut

    akun++; // untuk menambahkan akun(index) ex: auser [1] akun ke-1, auser [2] akun ke-2 dst..
    
    cout<< "\n   +++++++++++++++++++\n";
    cout<< "@@-PENDAFTARAN BERASIL-@@\n";
    cout<< "   +++++++++++++++++++\n\n";

}
void login(void)
{
    string user, password;
    cout << "Masukkan Username\t: ";
    cin >> user;
    cout << "Masukkan Password\t: ";
    cin >> password;
    int i;
    bool sudahterdaftar = false;// Dimulai dari false agar biar seirama dengan variabel secara harfiah
    for (i = 0; i < akun; i++) // Loop untuk mengecek/mencari/scannning indeks dari variabel akun(user dan password)
    {
        if (auser[i] == user)// Jika akun user cocok atau sudah ketemu maka akan ditandai sebagai akun yang sudah terdaftar
        {
            sudahterdaftar = true; // Jika akun sudah terdaftar (true) maka lanjut ke proses selanjutnya yaitu pencocokan password
            break;// break untuk berhenti scanning/mencari apabila sudah ketemu
        }
    }
    if (sudahterdaftar == false) // Jika belum terdaftar maka akan mengluarkan output tersebut
    {
        cout << "\n    --------------------\n";
        cout << "!!!!AKUN TIDAK TERDAFTAR!!!!" << endl;
        cout << "    --------------------\n\n";
        return; // Agar apabila user tidak ada atau tidak ketemu maka fungsi akan return dan tidak melanjutkan eksekusi syarat selanjutnya
    }

    if (apassword[i] == password)// Jika password yang dibuat cocok dengan passowrd yang di input maka output tersebut keluar dan program diakhiri
    {
        cout << "\n    ***************************";
        cout << "\n### SELAMAT ANDA BERHASIL LOGIN ###";
        cout << "\n    ***************************\n";
        exit(0); // Mengakhiri program
    }
    else //Jika password tidak sesuai/cocok maka akan meng-ouputkan seperti berikut dan kembali ke menu awal
    {
        cout << "Password Salah\n";
    }
}
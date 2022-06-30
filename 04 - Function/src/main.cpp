#include <iostream>
#include <windows.h>
using namespace std;

// Fungsi dengan return
int hitungLuasPersegiPanjang(int panjang, int lebar)
{
    cout << "Fungsi hitung luas persegi panjang dipanggil";
    Sleep(1500);
    cout << ".";
    Sleep(1500);
    cout << ".\n";
    return panjang * lebar;
}

// Fungsi void
void hitungKelilingPersegiPanjang(int panjang, int lebar)
{
    cout << "Fungsi hitung keliling persegi panjang dipanggil";
    Sleep(1500);
    cout << ".";
    Sleep(1500);
    cout << ".\n";
    cout << "Keliling persegi panjangnya adalah: " << 2 * (panjang + lebar) << endl;
}

int main()
{
    int luasPersegi, panjang, lebar;;

    cout << "===== Latihan Function =====\n\n";
    cout << "1. Hitung luas persegi panjang\n";
    cout << "2. Hitung keliling persegi panjang\n\n";

    cout << "Masukkan panjang persegi: ";
    cin >> panjang;
    cout << "Masukkan lebar persegi: ";
    cin >> lebar;

    // Memanggil fungsi dengan return
    luasPersegi = hitungLuasPersegiPanjang(panjang, lebar);
    cout << "Luas persegi panjangnya adalah: " << luasPersegi << endl;

    // Memanggil fungsi void
    hitungKelilingPersegiPanjang(panjang, lebar);

    return 0;
}
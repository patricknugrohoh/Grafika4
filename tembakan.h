#include "gambar.h"

typedef struct{
	int kemiringan; //kemiringan moncong tembakan, kemiringan peluru yang keluar
	int jedaTembak; //waktu terakhir menembak
	int isTembak;   //flag untuk tahu apakah tombol tembak ditekan
	titik posisi;   //posisi tembakan, titik tengah objek
}tembakan;

extern tembakan prime;

void puterTembakan(int a); //memutar kemiringan tembakan ke kiri atau kanan
void tembakTembakan(); //mengganti flag isTembak menjadi true dan mengganti jedaTembak
void sudahTembak(); //mengganti flag isTembak menjadi false;
int  cekJedaTembakan(); //mengecek apakah waktu terakhir menembak telah berlalu 2 detik, jika iya return true
void gambarTembakan(); //menggambar tembakan pada buffer, posisi objek berada di dalam gambar
#include "gambar.h"
#include "glob_var_type.h"
#include "framebuffer_init.h"

//objek dapat berupa peluru atau pesawat
typedef struct{
	titik posisi;	//posisi objek, titik tengah objek
	int kecepatan;  //kecepatan objek bergerak
	int arah;		//derajat kemana objek mengarah
	int status; //flag untuk mengecek apakah kolisi terjadi
	titik* citra;
}objekTabrak;

extern objekTabrak pesawat[10];
extern objekTabrak peluru[10];
extern objekTabrak objek[10];
extern objekTabrak propeller[10];

void cekTabrakanObjek(int offset);   //cek apakah terdapat peluru yang berada sejauh oTaffset dari pesawat,
								     //jika iya kedua objek memiliki isTabrakan tarue
void initPesawat();
void hancurObjek(objekTabrak* o);	 //hilangkan objek pesawat dari memori
void jalanObjek();					 //ganti posisi seluruh objek sesuai kecepatan dan arah
void spawnObjek(char t, titik p);	 //membuat objek baru(a=pesawat; b=peluru) pada posisi p
//=============================================================================================================================================
void gambarObjek();					 //menggambar seluruh objek dengan ke buffer, posisi objek berada di dalam gambar;
void gambarHancur(titik p);			 //menggambar animasi hancur pada titik p;

void setupCitraPesawat(objekTabrak *pesawat);
void setupCitraPeluru(objekTabrak *peluru);
void setupCitraPecah(objekTabrak *pecah, int type);
void setupCitraPropeller(objekTabrak *propeller);

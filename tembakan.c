#include "tembakan.h"
#include <time.h>
#include <math.h> 
#include <stdio.h>

const float rad = 3.14159265/180.0;

extern tembakan prime;
//memutar kemiringan tembakan ke kiri atau kanan
void puterTembakan(int a) {
	prime.kemiringan += a;
}

//mengganti flag isTembak menjadi true dan mengganti jedaTembak
void tembakTembakan() {
	if(cekJedaTembakan() == 1){
		prime.isTembak = 1;
		
		// get the current time
		time_t seconds;
		seconds = time(NULL);
		
		prime.jedaTembak = seconds;
	}
} 

//mengganti flag isTembak menjadi false;
void sudahTembak() {
	
	prime.isTembak = 0;

} 

//mengecek apakah waktu terakhir menembak telah berlalu 2 detik, jika iya return true
int cekJedaTembakan() {
	
	time_t curr_t;
	double diff_t;

	// get the current time
	time(&curr_t);

	// get the difference of seconds between current time and the last time of shooting
	diff_t = difftime(curr_t, prime.jedaTembak);
	
	if (diff_t > 2) {
		return 1;
	} else {
		return 0;
	}

} 

//menggambar tembakan pada buffer, posisi objek berada di dalam gambar
void gambarTembakan() {
	warna x = {100,99,0,98};

	drawTank(530, 610);

	int theta = (prime.kemiringan);
	int range = 300;

	titik p0 = {600, 650};
	titik p1 = {600, 650-range};

	int xx = p1.x;
	int yy = p1.y;

	p1.x = ((cos(theta*rad) * (xx-p0.x)) - (sin(theta*rad) * (yy-p0.y))) + p0.x;
	p1.y = ((sin(theta*rad) * (xx-p0.x)) + (cos(theta*rad) * (yy-p0.y))) + p0.y;

	bufferDrawLine(p0, p1, x);
} 

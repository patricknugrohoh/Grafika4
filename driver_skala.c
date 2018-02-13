#include "skala.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>


int main(){
	init_fb();
	warna c = {255,255,255,255};
	titik p0 = {0,0};
	titik p1 = {1366,700};
	
	titik px = {100, 100};
	titik py = {200, 200};
	
	titik pa = {150, 100};
	titik pb = {350, 300};

	refreshBuffer(p0,p1);
	bufferDrawLine(px, py, c);
	loadBuffer();			//gambar ke layar
	
	bufferDrawLine(pa, pb, c);
	loadBuffer();
	
	//bufferDrawLine(px, scaleDot(px, py, 2), c);
	//loadBuffer();
	
	return 0;
}

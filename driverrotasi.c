#include "rotasi.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>


titik rotasi (titik p0, titik p1, int d) {
//rotasi p1 terhadap pivot p0 sebesar d derajat
	titik p;
	double a = 0.017444;
	double sind = sin(d*a);
	double cosd = cos(d*a);
	
	p.x = ((p1.x-p0.x) * cosd ) - ((p1.y-p0.y) * sind) + p0.x;
	p.y = ((p1.x-p0.x) * sind ) - ((p1.y-p0.y) * cosd) + p0.y;
	
	return p;
	
}

titik* rotasibanyak (titik p0, titik* p1, int d, int l) {
//rotasi titik-titik pada array p1 dengan panjang l terhadap pivot p0 sebesar d derajat
	titik p[l];
	int i;
	for (i=0; i<l; l++) {
		p[i] = rotasi(p0, p1[i], d);
	}
	return p;
}

int main () {
	init_fb();
	warna c = {255,255,255,255};
	titik pl0 = {0,0};
	titik pl1 = {1000,600};

	titik p1 = {100,70};
	titik p3 = {600,650};
	
	refreshBuffer(pl0,pl1);
	loadBuffer();			//gambar ke layar
	bufferDrawLine(p1,p3,c);
	usleep(2000000);
	int i = 0;
	
	while(i<10000)
	{
		refreshBuffer(pl0,pl1);
		p3 = rotasi(p1,p3,30);
		bufferDrawLine(p1,p3,c);
		loadBuffer();

		usleep(170);
		i++;
	}
	return 0;
}


#include "gambar.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

int main() {
	init_fb();

	
	titik pFirst = {0,0};
	titik pLast = {1366,700};

	titik peluru[] = {{150,400},{155,405},{155,430},{145,430}, {145,405}};
	warna cPeluru = {25,255,25,255};

	int xofPesawat=10, yofPesawat=15;
	int xofTank=80, yofTank=600;
	while (1) {
		refreshBuffer(pFirst, pLast);
		drawPlane(xofPesawat, yofPesawat);
		drawTank(xofTank, yofTank);

		bufferDrawPlaneSolid(peluru, cPeluru, cPeluru, 5);
		loadBuffer();
		if (xofPesawat>1300) xofPesawat=0;
		else xofPesawat++;
		usleep(200);
	}
}
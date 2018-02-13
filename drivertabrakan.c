#include <stdlib.h>
#include "tabrakan.h"




void gambar(int x , int y){

	for (int i = x ; i < x+200 ; i ++){
		for (int j= y ; j < y+200 ; j ++){
			titik p = {i,j};
			warna c = {100,99,0,98};	
			bufferDrawDot(p, c);
	
		}
	}
	
}



	objekTabrak pesawat[1];
	objekTabrak peluru[5];
	

int main(){
	
	init_fb();	
	
	
	titik p3 = {0,0};
	titik p4 = {1000,1000};
	
	
	
	titik p0 = {1000,50};
	titik p1 = {400,400};
	
	
	spawnObjek('a',p0);
	spawnObjek('b',p1);
	
	
	
	while (1){
		
		
	refreshBuffer(p3,p4);
	loadBuffer();
	
	gambar(pesawat[0].posisi.x,pesawat[0].posisi.y);
	usleep(300000);
	gambar(peluru[0].posisi.x,peluru[0].posisi.y);
	usleep(300000);
	cekTabrakanObjek(300);
	jalanObjek();
	
	}
	
	garbage_fb();
	
	return 0;
}

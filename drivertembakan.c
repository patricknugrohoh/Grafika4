#include "tembakan.h"
#include <stdio.h>

int main() {
	
	init_fb();	
	
	// test gambarTembakan
	titik p3 = {0,0};
	titik p4 = {1000,1000};
			
	refreshBuffer(p3,p4);
	loadBuffer();
	
	gambarTembakan();
	
	
	//////////////////////////////////////////////////////
	
	
	// test tembakTembakan and cekJedaTembakan
	tembakTembakan();
	printf("tembakTembakan: %ld\n", prime.jedaTembak);
	
	//usleep(3000000);
	
	int cek = cekJedaTembakan();
	printf("cek: %d\n", cek);
		
	garbage_fb();
	
	return 0;
	
}

#include "tembakan.h"
#include "tabrakan.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

void drawObjects();		//menggambar tembakan dan objekTabrak ke buffer
void *preUpdate();		//(1)cek inputuser
void updatePosisi();	//(1)ubah posisi. (2)spawnObjek, (3)drawBuffer
void postUpdate();	 	//(1)cek kolisi, (2)loadbuffer ke layar

objekTabrak pesawat[10];
objekTabrak peluru[10];
objekTabrak objek[10];
objekTabrak propeller[10];
int pesawatterakhir = 0;
int peluruterakhir = 0;
int objekterakhir = 0;
titik pl0 = {0,0};
titik pl1 = {1366,700};
pthread_t thread0; 		//thread input capture
int fd; 				//something-something keylogger
struct input_event ev;	//something-something keylogger
ssize_t n;
int user_input = -99;
int keypress = 0;
titik p0 = {100,350};
titik p1 = {600,650};
titik p2 = {300,650};
titik p3 = {500,650};
titik p8 = {600, 650};
titik p9 = {0,0};
titik p10 = {760,2};
titik p11 = {0,600};
titik p12 = {1000,700};

int main(){
//**setup-pendengar-keyboard********************************************************************
	// Input keyboard device file
    //const char *dev = "/dev/input/by-id/usb-_USB_Keyboard-event-kbd";
    const char *dev = "/dev/input/event3";
    //const char *dev = "/dev/input/by-id/usb-_USB_Keyboard-event-kbd";
    // Open device for reference
    fd = open(dev, O_RDONLY);

    // Check if device is opened
    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
        return EXIT_FAILURE;
    }

//**setup-objek-game****************************************************************************
	init_fb();
	warna c = {255,255,255,255};
	warna c0 = {255,255,255,255};
	c0.r += 30;
    c0.g += 30;
    c0.b += 30;

	titik pt[3];
	pt[0] = pl0;
	pt[1] = p0;
	pt[2] = p1;

	for(int in=0; in<10; in++)
	{
		peluru[in].status = -1;
		pesawat[in].status = -1;
		objek[in].status = -1;
	}

	spawnObjek('a',p0);


	refreshBuffer(pl0,pl1);
	gambarObjek();
	gambarTembakan();
	loadBuffer();


//**game-loop***********************************************************************************
	pthread_create(&thread0, NULL, preUpdate, NULL);
	while(1)
	{
		//preUpdate();
		updatePosisi();
		postUpdate();
		usleep(17);
	}

//**garbaging***********************************************************************************
	//pthread_join(thread0, NULL);
	garbage_fb();
    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
	return 0;
}



void *preUpdate(){
	while(1){
		// get stored value on keyboard device reference file
	    n = read(fd, &ev, sizeof ev);
	    // check if no stored value on device file
	    if (n == (ssize_t)-1) {

	    }

	    // if keystroke is stored on keyboard device reference file
	    if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2){
	        if(ev.value == 1){ // when it pressed, 0 is released
	            switch(ev.code){
	                case 57:
	                    // Space trigger
	                    user_input = 0;
	                    printf("%d\n", peluruterakhir);
	                    break;

	                case 105:
	                    // Left arrow trigger
	                    user_input = -1;
	                    break;

	                case 106:
	                    // Right arrow trigger
	                    user_input = 1;
	                    break;

	                default:
	                    break;

	            }
	            keypress = 1;
	        }

	        if(ev.value == 0){
	        	keypress = 0;
	        }
	    }
	}
}

void updatePosisi(){
	//CEK INPUT
	if(user_input == 0){
		tembakTembakan();
		if(keypress == 0) user_input = -99;
	}
	else if(user_input == 1){
		puterTembakan(user_input);
		if(keypress == 0) user_input = -99;
	}
	else if(user_input == -1){
		puterTembakan(user_input);
		if(keypress == 0) user_input = -99;
	}

	//CEK FLAG
	if(prime.isTembak){
		spawnObjek('b',p1);
		sudahTembak();
	}

	refreshBuffer(pl0,pl1);
	gambarObjek();
	gambarTembakan();
	jalanObjek();
}

void postUpdate(){
	cekTabrakanObjek(100);

	for(int i=0; i<1; i++){
		if(pesawat[i].status == 1){
			gambarHancur(pesawat[i].posisi);
			pesawat[i].status = -1;
		}
	}

	for(int i=0; i<99; i++){
		if(peluru[i].status == 1){
			peluru[i].status = -1;
		}
	}

	loadBuffer();
}

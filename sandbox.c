#include "gambar.h"
#include "framebuffer_init.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

//inisialisasi***********************************************************************************
void *preUpdate();		//(1)cek inputuser
void updatePosisi();	//(1)ubah posisi. (2)spawnObjek, (3)drawBuffer
void postUpdate();	 	//(1)cek kolisi, (2)loadbuffer ke layar

titik pl0 = {0,0};
titik pl1 = {1366,700};
pthread_t thread0; 		//thread input capture
int fd; 				//something-something keylogger
struct input_event ev;	//something-something keylogger
ssize_t n;
int user_input = -99;
int keypress = 0;
//inisialisasi***********************************************************************************

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

	refreshBuffer(pl0,pl1);
	loadBuffer();


//**game-loop***********************************************************************************
	pthread_create(&thread0, NULL, preUpdate, NULL);
	while(1)
	{
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
		if(keypress == 0) user_input = -99;
	}
	else if(user_input == 1){
		if(keypress == 0) user_input = -99;
	}
	else if(user_input == -1){
		if(keypress == 0) user_input = -99;
	}

	//CEK FLAG


	refreshBuffer(pl0,pl1);
	// gambarObjek();
	// gambarTembakan();
	// jalanObjek();
}

void postUpdate(){
	

	loadBuffer();
}

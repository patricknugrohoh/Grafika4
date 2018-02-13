// source: http://stackoverflow.com/questions/4996777/paint-pixels-to-screen-via-linux-framebuffer

#ifndef FRAMEBUFFER_INIT_H
#define FRAMEBUFFER_INIT_H

// printf()
#include <stdio.h>

// exit(), usleep()
#include <stdlib.h>

// close(), usleep()
#include <unistd.h>

// Framebuffer dependencies library
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

// Variabel Statis Global
extern struct fb_var_screeninfo    global_vinfo;
extern struct fb_fix_screeninfo    global_finfo;
extern long int                    global_screensize;
extern int                         global_fbfd;
extern char                        *global_fbp;

// Inisialisasi Framebuffer.
// Melakukan inisialisasi terhadap lima 
// variabel statis global diatas.
void init_fb();

// Melakukan delokasi dan variabel statis diatas
// dan deattach hal-hal yang dibutuhkan.
void garbage_fb();

// Deklarasi awal variabel statis global
struct fb_var_screeninfo    global_vinfo;
struct fb_fix_screeninfo    global_finfo;
long int                    global_screensize;
int                         global_fbfd;
char                        *global_fbp;

#endif //FRAMEBUFFER_INIT_H

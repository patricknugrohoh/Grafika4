#include "framebuffer_init.h"

void init_fb(){

    int         x               = 0;
    int         y               = 0;
    long int    location        = 0;

    printf("Log 1");

    // Membuka driver framebuffer
    global_fbfd = open("/dev/fb0", O_RDWR);
    if (global_fbfd == -1) {
        perror("Error: driver framebuffer tidak dapat dibuka");
        exit(1);
    }

    printf("Log 2");

    // Get fixed screen information
    if (ioctl(global_fbfd, FBIOGET_FSCREENINFO, &global_finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(global_fbfd, FBIOGET_VSCREENINFO, &global_vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    printf("Informasi Layar: %dx%d px, %dbits per pixel\n", global_vinfo.xres, global_vinfo.yres, global_vinfo.bits_per_pixel);

    // Mengubah ukuran layar ke satuan bytes
    global_screensize = global_vinfo.xres * global_vinfo.yres * global_vinfo.bits_per_pixel / 8;

    // Mapping driver framebuffer ke memori
    global_fbp = (char *) mmap(0, global_screensize, PROT_READ | PROT_WRITE, MAP_SHARED, global_fbfd, 0);
    if((int)global_fbp == -1){
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
}

void garbage_fb(){
    munmap(global_fbp, global_screensize);
    close(global_fbfd);
}

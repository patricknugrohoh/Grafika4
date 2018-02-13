// usleep()
#include <stdlib.h>

// init_fb() dan garbage_fb()
#include "framebuffer_init.h"

// bufferDrawDot(), refreshBuffer(), dan loadBuffer()
#include "gambar.h"

// Kotak hijau di posisi (50, 150) sampai (50, 150)
void test_buffer_draw_dot(){
    int i, j;
    for(i = 0; i < 100; i++)
        for(j = 0; j < 100; j++){
            titik e = {50 + i, 50 + j};
            warna x = {20, 254, 76, 255};
            bufferDrawDot(e, x);
        }
}

// Memuat framebuffer pada posisi (0, 100) sampai (0, 100)
// dengan gradiasi warna hitam (0d, 0d, 0d)
// ke abu-abu (100d, 100d, 100d)
void test_load_buffer(){
    int i, j;
    for(i = 0; i < 100; i++)
        for(j = 0; j < 100; j++){
            buffer_r[i][j] = i + j;
            buffer_g[i][j] = i + j;
            buffer_b[i][j] = i + j;
            buffer_a[i][j] = 255;
        }

    loadBuffer();
}

// Membersihkan layar dengan warna default 
// pada posisi (25, 25) ke (250, 250)
void test_refresh_buffer(){
    titik p0 = {25, 25};
    titik p1 = {250, 250};

    refreshBuffer(p0, p1);
}

int main(){

    // !! strict !! harus diimplementasi
    init_fb();

    // Test #1
    test_buffer_draw_dot();
    usleep(1000000);

    // Test #2
    test_load_buffer();
    usleep(1000000);

    // Test #3
    test_refresh_buffer();
    loadBuffer();

    // !! strict !! harus diimplementasi
    garbage_fb();

    return 0;
}
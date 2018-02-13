#ifndef GLOB_VAR_TYPE_H
#define GLOB_VAR_TYPE_H

#define GLOBAL_LAYAR_X 1366
#define GLOBAL_LAYAR_Y 700

typedef struct{
    int r,g,b,a;
} warna;

typedef struct{
	int x;
	int y;
} titik;

extern unsigned char buffer_r[GLOBAL_LAYAR_X][GLOBAL_LAYAR_Y];
extern unsigned char buffer_g[GLOBAL_LAYAR_X][GLOBAL_LAYAR_Y];
extern unsigned char buffer_b[GLOBAL_LAYAR_X][GLOBAL_LAYAR_Y];
extern unsigned char buffer_a[GLOBAL_LAYAR_X][GLOBAL_LAYAR_Y];

#endif //GLOB_VAR_TYPE_H
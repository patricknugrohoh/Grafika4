#ifndef REFLEKSI_H
#define REFLEKSI_H
#include "gambar.h"

//mengembalikan titik p yang sudah dicerminkan oleh pAxis terhadap sumbu axis
//contoh p(1,2) dicerminkan pada titik pAxis(3,0) pada sumbu x menjadi (1,-2)
//jika pada sumbu y menjadi (5,2)
titik reflectDot(titik p, char axis, titik pAxis);

//mengembalikan array titik yang sudah dicerminkan oleh pAxis pada sumbu axis
void reflectDotArray(titik* p, int size, char axis, titik pAxis);

#endif
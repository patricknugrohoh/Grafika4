#include "refleksi.h"
#include <stdio.h>

titik reflectDot(titik p, char axis, titik pAxis){
	titik pResult;
	pResult.x = 0;
	pResult.y = 0;
	if(axis == 'x'){
		if(p.y > pAxis.y){
			int diff = p.y - pAxis.y;
			pResult.y = pAxis.y - diff;
			pResult.x = p.x;
		}
		else {
			int diff = pAxis.y - p.y;
			pResult.y = pAxis.y + diff;
			pResult.x = p.x;
		}
	}
	else if(axis == 'y'){
		if(p.x > pAxis.x){
			int diff = p.x - pAxis.x;
			pResult.x = pAxis.x - diff;
			pResult.y = p.y;
		}
		else {
			int diff = pAxis.x - p.x;
			pResult.x = pAxis.x + diff;
			pResult.y = p.y;
		}
	}
	return pResult;
}

//mengembalikan array titik yang sudah dicerminkan oleh pAxis pada sumbu axis
void reflectDotArray(titik* p, int size, char axis, titik pAxis){
	//titik* pResult;
	for(int i=0; i<size; i++){
		p[i] = reflectDot(p[i], axis, pAxis);
	}
}

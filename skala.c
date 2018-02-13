#include "skala.h"
#include <math.h>

titik scaleDot(titik p0, titik p1, float s){
	titik output;
	output.x = p1.x;
	output.y = p1.y;
	int jarakx = abs(p1.x - p0.x);
	int jaraky = abs(p1.y - p0.y);
	if (p1.x < p0.x){
		output.x = ((int)(((float)p0.x) - ((float)jarakx * s)));
	}
	else {
		output.x = ((int)(((float)p0.x) + ((float)jarakx * s)));
	}
	if (p1.y < p0.y){
		output.y = ((int)(((float)p0.x) - ((float)jarakx * s)));
	}
	else {
		output.y = ((int)(((float)p0.x) + ((float)jarakx * s)));
	}
	
	
	
	return output;
}

void scaleBanyakDot(titik p0, titik *p1, float s, int banyaktitik){
	for (int i = 0; i < banyaktitik;i++){
		scaleDot(p0, p1[i], s);
	}
} 

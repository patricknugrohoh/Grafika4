#include "rotasi.h"
#include <math.h>

titik rotasi (titik p0, titik p1, int d) {
//rotasi p1 terhadap pivot p0 sebesar d derajat
	titik p;
	double a = acos(-1) / 180;
	double sind = sin(d*a);
	//printf("sin = %f\n ", sind);
	double cosd = cos(d*a);
	//printf("cos = %f\n ", cosd);

	p.x = ((p1.x-p0.x) * cosd ) - ((p1.y-p0.y) * sind) + p0.x;
	p.y = ((p1.x-p0.x) * sind ) + ((p1.y-p0.y) * cosd) + p0.y;

	return p;
}

void rotasibanyak (titik p0, titik* p1, int d, int l) {
//rotasi titik-titik pada array p1 dengan panjang l terhadap pivot p0 sebesar d derajat
	titik* p = p1;
	int i;
	for (i=0; i<l; i++) {
		p1[i] = rotasi(p0, p1[i], d);
	}
}

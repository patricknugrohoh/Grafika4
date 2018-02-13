#include "translasi.h"
titik translateDot(titik p0, int x, int y){
//menggeser titik p0 sejauh x dan sejauh y
	titik p;
	p.x = p0.x + x;
	p.y = p0.y + y;
	return p;
}
void teleportDot(titik* p0, titik p1){
//mengubah nilai p0 menjadi p1
	(*p0).x = p1.x;
	(*p0).y = p1.y;
}	
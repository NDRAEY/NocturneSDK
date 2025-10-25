// Math library by NDRAEY

#include "math.h"

size_t fac(size_t x) {
	size_t a = 1;

	for (size_t i = 1; i < x + 1; i++) {
		a *= i;
	}
	
	return a;
}

double deg2rad(double deg) {
	return deg * (PI / 180.0);
}

double rad2deg(double rad) {
	return rad * (180.0 / PI);
}
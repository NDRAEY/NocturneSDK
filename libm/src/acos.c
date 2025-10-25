#include "math.h"

double acos(double x) {
	if(x < -1.0 || x > 1.0) {
		return NAN;
	}

	return PI / 2.0 - asin(x);
}
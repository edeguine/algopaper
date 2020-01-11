#ifndef COLORSPACE_H 
#define COLORSPACE_H

#include <math.h>

typedef struct {
    double r;       // percent
    double g;       // percent
    double b;       // percent
} rgb;

typedef struct {
    double h;       // angle in degrees 0 - 360
    double s;       // 0 - 1
    double v;       // 0 - 255
} hsv;

class Colorspace {
	public:
		static float bidirmod(float value, float min, float max);
		static hsv rgb2hsv(rgb in);
		static rgb hsv2rgb(hsv in);
};

#endif

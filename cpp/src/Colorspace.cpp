#include "Colorspace.h"
#include "utilcore.h"

float Colorspace::bidirmod(float value, float min, float max) {
    // Float modulo, brings value between min and max

	float res = value;
	float vmin = (min < max) ? min : max;
	float vmax = (max > min) ? max : min;

	while(res < vmin) {
		res += (vmax - vmin);
	}

	while(res > vmax) {
		res -= (vmax - vmin);
	}
	
	return res;
}

hsv Colorspace::rgb2hsv(rgb in) {
    // Converts RGB colors to HSV

    hsv         out;
    double      min, max, delta;

    min = in.r < in.g ? in.r : in.g;
    min = min  < in.b ? min  : in.b;
    max = in.r > in.g ? in.r : in.g;
    max = max  > in.b ? max  : in.b;

    out.v = max; // v
    delta = max - min;
    if (delta < 0.00001) {
        out.s = 0;
        out.h = 0; // undefined, maybe nan?
        return out;
    }

    if( max > 0.0 ) { // Avoids division by zero
        out.s = (delta / max); // s
    } else {
        // if max is 0, then r = g = b = 0  
        out.s = 0.0;
        out.h = 0; 
        return out;
    }
    if(in.r >= max)
        out.h = (in.g - in.b) / delta;        // between yellow & magenta
    else
    if(in.g >= max)
        out.h = 2.0 + (in.b - in.r) / delta;  // between cyan & yellow
    else
        out.h = 4.0 + (in.r - in.g) / delta;  // between magenta & cyan

    out.h *= 60.0; // degrees

    while(out.h < 0.0 ) {
        out.h += 360.0;
	}

    return out;
}

rgb Colorspace::hsv2rgb(hsv in) {
    // HSV to RGB conversion

    double hh, p, q, t, ff;
    long i;
    rgb out;
   
    in.h = Colorspace::bidirmod(in.h, 0.0f, 360.0f);
    in.s = Colorspace::bidirmod(in.s, 0.0f, 1.0f);
    in.v = Colorspace::bidirmod(in.v, 0.0f, 255.0f);
    
    hh = in.h;
    
    if(hh >= 360.0) hh = 0.0;
    hh /= 60.0;
    i = (long) hh;
    ff = hh - i;
    p = in.v * (1.0 - in.s);
    q = in.v * (1.0 - (in.s * ff));
    t = in.v * (1.0 - (in.s * (1.0 - ff)));
    switch(i) {
    case 0:
        out.r = in.v;
        out.g = t;
        out.b = p;
        break;
    case 1:
        out.r = q;
        out.g = in.v;
        out.b = p;
        break;
    case 2:
        out.r = p;
        out.g = in.v;
        out.b = t;
        break;
    case 3:
        out.r = p;
        out.g = q;
        out.b = in.v;
        break;
    case 4:
        out.r = t;
        out.g = p;
        out.b = in.v;
        break;
    case 5:
    default:
        out.r = in.v;
        out.g = p;
        out.b = q;
        break;
    }

    return out;     
}

#ifndef GRADIENT_H
#define GRADIENT_H

#include "myColorRGB.h"
#include "myPoint.h"
#include "myImage.h"

class Gradient {
	public:
    static myColorRGB Hue(float t, float cycle);
	static void	linearGradient(myImage *mim, vector<myPoint> centers, vector<myColorRGB> palette);
	static void rainbow(myImage *mim, myPoint minXY, myPoint maxXY, myPoint direction);
    static void sampleGradient(myImage *mim, vector<myColorRGB> *palette);
};

#endif

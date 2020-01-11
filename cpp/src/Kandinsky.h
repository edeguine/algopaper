#ifndef KANDINSKY_H 
#define KANDINSKY_H

#include "Gradient.h"
#include "myColorRGB.h"
#include "myCImage.h"
#include "myImage.h"
#include "myPoint.h"
#include "Selecter.h"
#include "utilcore.h"

class Kandinsky {

	public:
		static void pipeline(myImage *mim, float threshold = 0.5, vector<myColorRGB> *palette = nullptr, myPoint gradStart= myPoint(100, 0), myPoint gradEnd = myPoint(400, 400));
		static void androidSeparateBW(int *pixels, int w, int h, float threshold, string jparam);
		static void androidPalette(int *pixels, int w, int h, string jpalette);
		static void extractGradientDirection(string jparam, myPoint *gradStart, myPoint *gradEnd);
		static void distributePoints(myImage *mim, int n, myPoint start, myPoint end, vector<myPoint> *res);
};

#endif

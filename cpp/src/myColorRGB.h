#ifndef MYCOLORRGB_H
#define MYCOLORRGB_H

#include <iostream>
#include <vector>

#include "myPoint.h"
#include "Colorspace.h"

#define CV_DESCALE(x, n) (((x) + (1 << ((n)-1))) >> (n))

#define NORMAL 0
#define SCREEN 1
#define MULTIPLY 2

class myImage;

class myColorRGB {

	public:

		unsigned char r, g, b, a;

		float x = 0;
		float y = 0;
		float z = 0; // for CIE coordinates

		float X = 0;
		float Y = 0;
		float Z = 0;
		
		float Ca = 0;
		float Cb = 0;
		float CL = 0;
		/*
			A in [-86.185, 98,254]
			B in [-107.863, 94.482]
		*/
		int mix_mode = 0; // which mode was used to mix the color in the CIE space


	  // For computing the CieLAB coordinates
		float X0 = 95.047f;
		float Y0 = 100.0f;
		float Z0 = 108.883f;

		myColorRGB() : r(0), g(0), b(0), a(255) {};
		myColorRGB(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a = 255):
			r(_r), g(_g), b(_b), a(_a) {};

		unsigned char red() {return r;};
		unsigned char green() {return g;};
		unsigned char blue() {return b;};
		unsigned char alpha() {return a;};

	  
        hsv col2hsv();
        static myColorRGB hsv2col(hsv in);
        static myColorRGB hsvMix(myColorRGB cola, myColorRGB colb, float coeff);
        static myColorRGB hsvMix(vector<myColorRGB> *col, vector<float> *concentrations);
        static myColorRGB cielMix(myColorRGB cola, myColorRGB colb, float coeff);
        static myColorRGB cielMix(vector<myColorRGB> *colors, vector<float> *concentrations);

        void computeCiel();
        void inverseCiel();
};

static myColorRGB myyellow = myColorRGB(247, 197, 22);
static myColorRGB myred = myColorRGB(238, 70, 48);
static myColorRGB myblue = myColorRGB(4, 40, 122);
static myColorRGB mypurple = myColorRGB(115, 0, 198);
static myColorRGB mypink = myColorRGB(250, 105, 145);
static myColorRGB myblack = myColorRGB(0 , 0, 0);
static myColorRGB mywhite = myColorRGB(255 , 255, 255, 0);
static myColorRGB mygreen = myColorRGB(3, 255, 0);

#endif

#include <random>
#include <vector>

#include "Colorspace.h"
#include "myColorRGB.h"
#include "myImage.h"
#include "utilcore.h"

using namespace std;

hsv myColorRGB::col2hsv() {
	rgb in;
	in.r = r;
	in.g = g;
	in.b = b;
	return Colorspace::rgb2hsv(in);
}

myColorRGB myColorRGB::hsv2col(hsv in) {
	rgb out = Colorspace::hsv2rgb(in);
	return myColorRGB(out.r, out.g, out.b);
}

myColorRGB myColorRGB::hsvMix(vector<myColorRGB> *col, vector<float> *concentrations) {
	hsv in, mix;
	float concentration = 0;
	float tot = 0;
	myColorRGB c;

	for(float concentration: *concentrations) {
		tot += concentration;
	}

	for(int i = 0; i < concentrations->size(); i++) { 
		c = col->at(i);
		concentration = concentrations->at(i);
		in = c.col2hsv();
		mix.h += concentration * in.h / tot;
		mix.v += concentration * in.v / tot;
		mix.s += concentration * in.s / tot;
	}
	return myColorRGB::hsv2col(mix);
}

myColorRGB myColorRGB::hsvMix(myColorRGB cola, myColorRGB colb, float coeff) {
	
	hsv ina, inb, mix;
	ina = cola.col2hsv();
	inb = colb.col2hsv();

	mix.h = coeff * ina.h + (1 - coeff) * inb.h;	
	mix.s = coeff * ina.s + (1 - coeff) * inb.s;	
	mix.v = coeff * ina.v + (1 - coeff) * inb.v;	

	return myColorRGB::hsv2col(mix);
}


myColorRGB myColorRGB::cielMix(vector<myColorRGB> *colors, vector<float> *concentrations) {

	int mode = 0; 

	myColorRGB current;
	myColorRGB mix(0, 0, 0);
	mix.computeCiel();

  mix.x = 0;
  mix.y = 0;
  mix.X = 0;
  mix.Y = 0;
  mix.Z = 0;
    
   float coeff, tot;
	 coeff = 0;
	 tot = 0;

	 for(int i = 0; i < concentrations->size(); i++) {
	 	tot += concentrations->at(i);
	 }

	// We can mix in x, y, Y
  // or X Y Z

	for(int i = 0; i < concentrations->size(); i++) {
        coeff = concentrations->at(i);
        current = colors->at(i);
        current.computeCiel();
        
		switch(mode) {
			case 0:
				mix.x += coeff / tot * current.x; 
				mix.y += coeff / tot * current.y;
				mix.Y += coeff / tot * current.Y;
				break;
			case 1:
				mix.X += coeff / tot * current.X;
				mix.Y += coeff / tot * current.Y;
				mix.Z += coeff / tot * current.Z;
			break;
		}
	}
	mix.inverseCiel();
	return mix;
}

myColorRGB myColorRGB::cielMix(myColorRGB cola, myColorRGB colb, float coeff) {
	cola.computeCiel();
	colb.computeCiel();

	int mode = 0; 

	myColorRGB colc;
	// We can mix in x, y, Y
  // or X Y Z
	switch(mode) {

		case 0:
			colc.x = coeff * cola.x + (1 - coeff) * colb.x;
			colc.y = coeff * cola.y + (1 - coeff) * colb.y;
			colc.Y = coeff * cola.Y + (1 - coeff) * colb.Y;
			break;
		case 1:
			colc.X = coeff * cola.X + (1 - coeff) * colb.X;
			colc.Y = coeff * cola.Y + (1 - coeff) * colb.Y;
			colc.Z = coeff * cola.Z + (1 - coeff) * colb.Z;
			break;
	} 
	colc.inverseCiel();
	return colc;
}
void myColorRGB::inverseCiel() {
	// Y is already specified;
	if(mix_mode == 0) {
		X = Y * x / y;
		Z = Y * (1 - x - y) / y;
	}

	X = X / 100.0f;        //X from 0 to  95.047      (Observer = 2°, Illuminant = D65)
	Y = Y / 100.0f;        //Y from 0 to 100.000
	Z = Z / 100.0f;        //Z from 0 to 108.883

	float R, G, B;

	R = X *  3.2406f + Y * -1.5372f + Z * -0.4986f;
	G = X * -0.9689f + Y *  1.8758f + Z *  0.0415f;
	B = X *  0.0557f + Y * -0.2040f + Z *  1.0570f;

	R = (R > 0.0031308f) ?  1.055f * (pow(R, (1.0f / 2.4f))) - 0.055f: 12.92f * R;
	G = (G > 0.0031308f) ? 1.055f * (pow(G, (1.0f / 2.4f))) - 0.055f: 12.92f * G;
  B = (B > 0.0031308f) ? 1.055f * (pow(B, (1.0f / 2.4f))) - 0.055f: 12.92f * B;

	R = R > 1.0f ? 1.0f : R;
	G = G > 1.0f ? 1.0f : G;
	B = B > 1.0f ? 1.0f : B;

	r = R * 255;
	g = G * 255;
	b = B * 255;
}

void myColorRGB::computeCiel() {
	float R = (r / 255.0f);
	float G = (g / 255.0f);
	float B = (b / 255.0f);

	R = R > 0.04045f ?
		pow(((R + 0.055f) / 1.055f) , 2.4f): 
		R / 12.92f;
  G = G > 0.04045f ?
		pow(((G + 0.055f) / 1.055f), 2.4f):
		G / 12.92f;
	B = B > 0.04045f?
		pow(((B + 0.055f) / 1.055f) , 2.4f):
		B / 12.92f;
	
	R *= 100;
	G *= 100;
	B *= 100;

	//Observer. = 2°, Illuminant = D65
	X = R * 0.4124f + G * 0.3576f + B * 0.1805f;
	Y = R * 0.2126f + G * 0.7152f + B * 0.0722f;
	Z = R * 0.0193f + G * 0.1192f + B * 0.9505f;

	x = X / (X + Y + Z);
	y = Y / (X + Y + Z);
	z = Z / (X + Y + Z);
}



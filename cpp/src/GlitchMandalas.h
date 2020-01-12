#ifndef GLITCHMANDALAS_H
#define GLITCHMANDALAS_H

#include "myImage.h"
#include "myColorRGB.h"
#include "utilcore.h"

class GlitchMandalas {

	public:
		static void render(myImage *mim);
		static myColorRGB getColorFromDist(float scale, float dist);
		static float getFloatFromDist(float scale, float dist);

};

#endif

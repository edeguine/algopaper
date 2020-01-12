#include "GlitchMandalas.h"

void GlitchMandalas::render(myImage *mim) {

	myPoint current, center;
	center.x = mim->w / 2.0f;
	center.y = mim->h / 2.0f;
	int offset;
	float scale = utilcore::randomFloat(1000, 100000);
	cout << "Scale " << scale << endl;

	myColorRGB col;
	float dist;
	scale = 100000; // 100000 is a good value

	float mix;	

	for(int i = 0; i < mim->w; i++) {
		for(int j = 0; j < mim->h; j++) {
			current.x = i;
			current.y = j;
		
			dist = center.dist(current);
			col = GlitchMandalas::getColorFromDist(scale, dist);
			mix = GlitchMandalas::getFloatFromDist(scale, dist);
			col = myColorRGB::hsvMix(mypurple, myyellow, mix);
			
			mim->setCol(current, col);
		}
	}
}

float GlitchMandalas::getFloatFromDist(float scale, float dist) {
	return fmodf(dist * scale, 255.0f) / 255.0f;
}

myColorRGB GlitchMandalas::getColorFromDist(float scale, float dist) {

	float v = fmodf(dist * scale, 255.0f);

	hsv hcol;
	hcol.h = 266.0f;
	hcol.s = 0.7;
	hcol.v = fmodf(v, 255.0f);


	return myColorRGB::hsv2col(hcol);
}

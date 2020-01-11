#include "SpiralColorsFade.h"

void SpiralColorsFade::androidSpiralColorsFade(int *pixels, int w, int h, string jparam) {
    myImage *mim;
    mim = (myImage *) new myCImage(w, h);
    utilcore::importARGB8888(pixels, w, h, mim);
    SpiralColorsFade::processSpiralColorsFade(mim, jparam);
    utilcore::exportARGB8888(mim, pixels, w, h);
}

void SpiralColorsFade::processSpiralColorsFade(myImage *mim, string jparam) {

	/*
		The algorithm is:
		 - go through the points
		 - compute angle
		 - compute radius
		 - fill accordingly

         Params:
         baseradius : 100 - 1000
         fademultiplier: 200 - 1000

	*/

	myPoint center, current;
	float angle, radius;

	center.x = mim->w / 2.0f;
	center.y = mim->h / 2.0f;

	myColorRGB col;
	hsv in;

	float baseradius = JSONUtils::loadParam(jparam, "BaseRadius", 500.0f);
	float fademultiplier = JSONUtils::loadParam(jparam, "FadeMultiplier", 800.0f);
	float fade = 0;

	for(int i = 0; i < mim->w; i++) {
		for(int j = 0; j < mim->h; j++) {

			current.x = i;
			current.y = j;
			
			angle = myPoint::angle(center, center + myPoint(1.0f, 0),  current);
			radius = (current - center).L2();

			fade = exp(-1.0f * radius / baseradius);

			in.h = fmodf(cos(angle) * fade * fademultiplier, 360.0f);
			in.s = 0.8f;
			in.v = 200.0f;

			col = myColorRGB::hsv2col(in);
			mim->setCol(current, col);
		}
	}

}

#include "SpiralColorsFadeMulti.h"

void SpiralColorsFadeMulti::androidSpiralColorsFadeMulti(int *pixels, int w, int h, string jparam) {
    myImage *mim;
    mim = (myImage *) new myCImage(w, h);
    utilcore::importARGB8888(pixels, w, h, mim);
    SpiralColorsFadeMulti::processSpiralColorsFadeMulti(mim, jparam);
    utilcore::exportARGB8888(mim, pixels, w, h);
}

void SpiralColorsFadeMulti::processSpiralColorsFadeMulti(myImage *mim, string jparam) {

	/*
		The algorithm is:
		 - go through the points
		 - compute angle
		 - compute radius
		 - fill accordingly


         Params:
         baseradius 100 - 1000
         fademultiplier 1 - 100
         countcenters 1 - 50

	*/

	myPoint center, current;
	float angle, radius;

	vector<myPoint> *centers;
	centers = new vector<myPoint>();

	float baseradius = JSONUtils::loadParam(jparam, "BaseRadius", 100.0f);
    float fademutlplier = JSONUtils::loadParam(jparam, "FadeMutliplier", 10.0f);
	float fade = 0;

    int ncenters = JSONUtils::loadParam(jparam, "CountCenters", 25);

	for(int i = 0; i < ncenters; i++) {
		center.x = utilcore::randomFloat(0, mim->w);
		center.y = utilcore::randomFloat(0, mim->h);

		centers->push_back(center);
	}

	myColorRGB col;
	hsv in;


	vector<myColorRGB> palette;
	palette = Palettes::Goldmine();

	for(int i = 0; i < mim->w; i++) {
		for(int j = 0; j < mim->h; j++) {

			current.x = i;
			current.y = j;
		
			in.h = 0;
			for(myPoint center: *centers) {
				angle = myPoint::angle(center, center + myPoint(1.0f, 0),  current);
				radius = (current - center).L2();

				fade = exp(-1.0f * radius / baseradius); // good param : -1.0f
				in.h += fmodf(cos(angle) * fade * fademutlplier, 360.0f); // good param : 10.0f
			}


			in.s = 0.8f;
			in.v = 200.0f;

			col = myColorRGB::hsv2col(in);
			// if using palette slight hack
			col  = palette.at((int) fmodf(in.h, palette.size()) % palette.size());
			//col = myyellow;
			
			mim->setCol(current, col);
		}
	}

}

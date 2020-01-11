#include "SpiralColors.h"

void SpiralColors::androidSpiralColors(int *pixels, int w, int h, string jparam) {
    myImage *mim;
    mim = (myImage *) new myCImage(w, h);
    utilcore::importARGB8888(pixels, w, h, mim);
    SpiralColors::processSpiralColors(mim, jparam);
    utilcore::exportARGB8888(mim, pixels, w, h);
}

void SpiralColors::processSpiralColors (myImage *mim, string jparam) {

	/*
		The algorithm is:
		 - go through the points
		 - compute angle
		 - compute radius
		 - fill accordingly

         Parameters:
         angleModulo: 0 - 2pi
         radiusModulo: 100 - 1000
         radiusPeriod: 100 - 1000

	*/

	myPoint center, current;
	float angle, radius, hueNorm;

	center.x = mim->w / 2.0f;
	center.y = mim->h / 2.0f;

	myColorRGB col;
	hsv in;

    float angleModulo = JSONUtils::loadParam(jparam, "angleModulo", 1.0f);
    float radiusModulo = JSONUtils::loadParam(jparam, "radiusModulo", 200.0f);
    float radiusPeriod = JSONUtils::loadParam(jparam, "radiusPeriod", 600.0f);

	for(int i = 0; i < mim->w; i++) {
		for(int j = 0; j < mim->h; j++) {

			current.x = i;
			current.y = j;
			
			angle = myPoint::angle(center, center + myPoint(1.0f, 0),  current);
			radius = (current - center).L2();

			in.h = fmodf(angle, angleModulo) + fmodf(radius, radiusModulo) / radiusPeriod;
            hueNorm = angleModulo + radiusModulo / radiusPeriod;
			in.h = fmodf(in.h, hueNorm) / hueNorm * 360.0f;

			in.s = 0.8f;
			in.v = 200.0f;

			col = myColorRGB::hsv2col(in);
			mim->setCol(current, col);
		}
	}

}

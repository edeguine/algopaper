#include "SnakeColors.h"

using namespace nlohmann;

void SnakeColors::androidSnakeColors(int *pixels, int w, int h, string jparam) {

    myImage *mim;
    mim = (myImage *) new myCImage(w, h);
    utilcore::importARGB8888(pixels, w, h, mim);
    SnakeColors::processSnakeColors(mim, jparam);
    utilcore::exportARGB8888(mim, pixels, w, h);
}

void SnakeColors::processSnakeColors(myImage *im, string jparam) {

	myPoint p;
	myColorRGB col;
	vector<myColorRGB> palette, tomix;
	vector<float> concentrations;

    // TODO import palette
	palette = Palettes::Tropicals();

    // Set parametesr
	float xperiod, yperiod, zperiod;
	xperiod = JSONUtils::loadParam<float>(jparam, "xperiod", 50.0f);
	yperiod = JSONUtils::loadParam<float>(jparam, "yperiod", 20.0f);
	zperiod = JSONUtils::loadParam<float>(jparam, "zperiod", 30.0f);

	vector<float> triSpace;

	// Finally using the triadic system
	// xperiod = yperiod = zperiod makes cute tiles
	// 1495657109.png
	// x,y,zperiod = 50, 20, 30 gives 1495665829.png

	for(int i = 0; i < im->w; i++) {
		for(int j = 0; j < im->h; j++) {
			p.x = i;
			p.y = j;

			triSpace.clear();
			tomix.clear();
			concentrations.clear();

			SpacePartitioning::cubesWithStripes(im, p, xperiod, yperiod, zperiod, &triSpace); 	
			
			tomix.push_back(palette.at(((int) triSpace.at(0)) % palette.size()));
			tomix.push_back(palette.at(((int) triSpace.at(1)) % palette.size()));
			tomix.push_back(palette.at(((int) triSpace.at(2)) % palette.size()));
			
			concentrations.push_back(triSpace.at(3));
			concentrations.push_back(triSpace.at(4));
			concentrations.push_back(triSpace.at(5));

			col = myColorRGB::cielMix(&tomix, &concentrations);
			im->setCol(p, col);
		}
    }
}

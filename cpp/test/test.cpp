#include <ctime>
#include <iomanip>
#include <iostream>
#include <png++/png.hpp>

#include "GlitchMandalas.h"
#include "PastelGradients.h"
#include "SpiralColors.h"
#include "SpiralColorsFade.h"
#include "SpiralColorsFadeMulti.h"
#include "SnakeColors.h"

using namespace std;

void testGlitchMandalas(myImage *mim) {
    GlitchMandalas::render(mim);
}

void testPastelGradients(myImage *mim) {
    string jparam = "{\"ph\": 20, \"yoffset\": 20, \"mixperiod\": 300}";
    PastelGradients::processPastelGradients(mim, jparam);
}

void testSnakeColors(myImage *mim) {
    string jparam = "{\"xperiod\": 25.0, \"yperiod\": 30.0, \"zperiod\": 35.0}";
    SnakeColors::processSnakeColors(mim, jparam);
}

void testSpiralColors(myImage *mim) {
    string jparam = "{\"angleModulo\": 1.2, \"radiusModulo\": 500.0, \"radiusPeriod\": 500.0}";
    SpiralColors::processSpiralColors(mim, jparam);
}

void testSpiralColorsFade(myImage *mim) {
    string jparam = "{\"BaseRadius\": 300.0, \"FadeMultiplier\": 400.0}";
    SpiralColorsFade::processSpiralColorsFade(mim, jparam);
}

void testSpiralColorsFadeMulti(myImage *mim) {
    string jparam = "{\"BaseRadius\": 300.0, \"FadeMultiplier\": 400.0, \"CountCenters\": 20}";
    SpiralColorsFadeMulti::processSpiralColorsFadeMulti(mim, jparam);
}



int main(int argc, char** argv) {
	cout << "starting " << endl;
	myColorRGB col;

	myImage *mim;
	if(argc > 1) {
		cout << "Loading image " << argv[1] << endl;
		png::image<png::rgba_pixel> imload(argv[1]);
		mim = new myCImage(imload.get_width(), imload.get_height());

		int r,g,b,a;
		for(int i = 0; i < mim->w; i++) {
			for(int j = 0; j < mim->h; j++) {
				r = imload[j][i].red;
				g = imload[j][i].green;
				b = imload[j][i].blue;
				a = imload[j][i].alpha;
				mim->setCol(myPoint(i, j), myColorRGB(r, g, b, a));
			}
		}
	} else {
		mim = new myCImage(800, 800);
	}

    testGlitchMandalas(mim);
    //testPastelGradients(mim);
    //testSnakeColors(mim);
    //testSpiralColors(mim);
    //testSpiralColorsFade(mim);
    //testSpiralColorsFadeMulti(mim);

	string outputfilename = "test.png";
	cout << "Writing " << outputfilename << endl;

	myColorRGB mycol;
	png::image<png::rgba_pixel> out(mim->w, mim->h);
	for(int i = 0; i < out.get_width(); i++) {
		for(int j = 0; j < out.get_height(); j++) {
			mycol = mim->getCol(myPoint(i, j));
			out[j][i].red = mycol.red();
			out[j][i].green = mycol.green();
			out[j][i].blue = mycol.blue();
			out[j][i].alpha = mycol.alpha();
		}
	}
	out.write(outputfilename);
}

#include "Kandinsky.h"

using namespace std;
using namespace nlohmann;

void Kandinsky::distributePoints(myImage *mim, int n, myPoint start, myPoint end, vector<myPoint> *res) {
	// Distribute n-2 points on the segment [start, end] and add points on [ifty, start] and [end, ifty] until we are out of the picture

	float dist = 0;
	myPoint p;
	if(n > 2) {
		dist = start.dist(end) / (n - 1);
	}

	if(n == 2) {
		dist = start.dist(end);
	}

	p = start;
	while(mim->inImage(p)) {
		p =  p + (start - end).scale(dist / (start.dist(end)));
	}

	res->push_back(p);

	while(!mim->inImage(p)) {
		p = p + (end - start).scale(dist / (start.dist(end)));
		res->push_back(p);
	}

	while(mim->inImage(p)) {
		p = p + (end - start).scale(dist / (start.dist(end)));
		res->push_back(p);
	}
}

void Kandinsky::extractGradientDirection(string jparam, myPoint *gradStart, myPoint *gradEnd) {
    // Helper function to get the anchor points from the JSON params

	json j = json::parse(jparam);
	gradStart->x = j["gradientDirection"]["start"]["x"];
	gradStart->y = j["gradientDirection"]["start"]["y"];

	gradEnd->x = j["gradientDirection"]["end"]["x"];
	gradEnd->y = j["gradientDirection"]["end"]["y"];
}

void Kandinsky::androidPalette(int *pixels, int w, int h, string jpalette) {
    // Creates a linear gradient rendering from a color palette to display in the UI

    myImage *mim;
    mim = (myImage *) new myCImage(w, h);
    utilcore::importARGB8888(pixels, w, h, mim);
    vector<myColorRGB> palette;
    utilcore::importPalette(jpalette, &palette);
    Gradient::sampleGradient(mim, &palette);
    utilcore::exportARGB8888(mim, pixels, w, h);
}

void Kandinsky::androidSeparateBW(int *pixels, int w, int h, float threshold, string jparam) {
    // Main function called by the Android app to read JSON parameters and perform the coloring

    myImage *mim;
    mim = (myImage *) new myCImage(w, h);
    utilcore::importARGB8888(pixels, w, h, mim);
    myPoint gradStart, gradEnd;
    Kandinsky::extractGradientDirection(jparam, &gradStart, &gradEnd);

	json j = json::parse(jparam);
    string type = j["type"];

    if(type == "rainbow") {
        Kandinsky::pipeline(mim, threshold, nullptr, gradStart, gradEnd);
    } else {
        vector<myColorRGB> palette;
        utilcore::importPalette(jparam, &palette);
        Kandinsky::pipeline(mim, threshold, &palette, gradStart, gradEnd);
    }

    utilcore::exportARGB8888(mim, pixels, w, h);
}


void Kandinsky::pipeline(myImage *mim, float threshold, vector<myColorRGB> *palette, myPoint gradStart, myPoint gradEnd) {
    
    /* In this function we:
      - add anchor points to cover the full picture
      - generates a gradient using gradStart and gradEnd as anchor points
      - color the black points with the gradient
    */
    

	myImage *gradient;
	gradient = (myImage *) new myCImage(mim->w, mim->h);
    bool isRainbow = (palette == nullptr);

	vector<myPoint> colorCenters;

    // Add anchor points
    if(!isRainbow) {
        Kandinsky::distributePoints(mim, palette->size() > 1? palette->size(): 2, gradStart, gradEnd, &colorCenters); 
    }


    // Color with the gradient
    if(isRainbow) {
        myPoint direction;
        direction = gradEnd - gradStart;
        Gradient::rainbow(gradient, gradStart, gradEnd, direction);
    } else {
        Gradient::linearGradient(gradient, colorCenters, *palette);
    }

    myColorRGB col;
    hsv h;
    float gray;
    myPoint p;

    for(int i = 0; i < mim->w; i++) {
        for(int j = 0; j < mim->h; j++) {
            p.x = i;
            p.y = j;
            col = mim->getCol(p);
            h = col.col2hsv();
            gray = h.v / 255.0f;

            if(gray <= threshold) {
               mim->setCol(p, gradient->getCol(p));
            } else {
                mim->setCol(p, myblack);
            }
        }
    }
}

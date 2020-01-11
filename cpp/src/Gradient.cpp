#include "Gradient.h"

myColorRGB Gradient::Hue(float t, float cycle) {
    // Returns a cyclical mapping of t into a color 

    hsv hcol;
    hcol.h = fmodf(fabs(t), cycle) * 360.0f / cycle;
    hcol.s = 1.0f;
    hcol.v = 200.0f;
    
    return myColorRGB::hsv2col(hcol);
}


void Gradient::linearGradient(myImage *mim, vector<myPoint> centers, vector<myColorRGB> palette) {
    // Linear gradient with the colors from palette using the first and last center as anchor points

	myPoint p;
	myColorRGB col;
	float concentration;
	int np = palette.size();
	int nc = centers.size();

	int first, second;
	float t = 0;
	myPoint start, end;
	start = centers[0];
	end = centers[centers.size() - 1];
	float d = end.dist(start);

	for(int i = 0; i < mim->w; i++) {
		for(int j = 0; j < mim->h; j++) {
			p.x = i;
			p.y = j;

			t = (p - start).dot(end - start) / (d * d); // Scalar product to get the projection on the linear axis (start, end)

			first = ((int) (t * nc)) % np; // Concentration between evenly spaced anchor points
			second = (first + 1) % np;
			concentration =	1.0f - fabs(t * nc - ((int) (t * nc)));

			col = myColorRGB::cielMix(palette.at(first), palette.at(second), concentration);
			mim->setCol(p, col);
		}
	}
}


void Gradient::rainbow(myImage *mim, myPoint minXY, myPoint maxXY, myPoint direction) {
    // Cyclical rainbow gradient with minXY and maxXY as anchoir points

	float period = direction.L2();

	float t;
	myPoint current;
	myColorRGB col;
	hsv h;

	for(int i = 0; i < mim->w; i++) {
		for(int j = 0; j < mim->h; j++) {
			current = myPoint(i, j);	
			t = (current - minXY).dot(direction) / period;
			col = Gradient::Hue(t, period);

			mim->setCol(current, col);
		}
	}
}

void Gradient::sampleGradient(myImage *mim, vector<myColorRGB> *palette) {
    // Used by the android app to turn a color palette into a linear gradient

	myPoint p;
	myColorRGB col;
	float concentration;
	int n = palette->size();
	int first, second;

	for(int i = 0; i < mim->w; i++) {
		for(int j = 0; j < mim->h; j++) {
			p.x = i;
			p.y = j;
			first = (i / (mim->w / n)) % n;
			second = (first + 1) % n;
			concentration =	1.0 - ((i * 1.0f / (mim->w / n)) - first);

			col = myColorRGB::cielMix(palette->at(first), palette->at(second), concentration);
			mim->setCol(p, col);
		}
	}
}

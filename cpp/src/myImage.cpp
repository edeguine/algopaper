#include "myImage.h"

bool myImage::inImage(myPoint point) {
	bool res = ((int) point.x >= 0 && (int) point.x < w) && ((int) point.y >= 0 && (int) point.y < h);
	return res;
}

myPoint myImage::randomPoint() {
    return myPoint(utilcore::randomFloat(0, w), utilcore::randomFloat(0, h));
}



void myImage::clear() {
	myPoint point(0, 0);
	for(int i = 0; i < w; i++) {
		for(int j = 0; j < h; j++) {
			point.x = i;
			point.y = j;
			setCol(point, mywhite);
		}
	}
}

void myImage::clearBlack() {
    myPoint point(0, 0);
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            point.x = i;
            point.y = j;
            setCol(point, myblack);
        }
    }
}

void myImage::copy(myImage *ref) {
	myPoint current;

	for(int i = 0; i < w; i++) {
		for(int j = 0; j < h; j++) {
			current.x = i;
			current.y = j;
			setCol(current, ref->getCol(current));
		}
	}
}

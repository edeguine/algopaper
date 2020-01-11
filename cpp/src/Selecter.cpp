//
//  Selecter.cpp
//  psychetouch
//
//  Created by Etienne on 2/1/17.
//  Copyright © 2017 Etienne. All rights reserved.
//

#include "Selecter.h"

void Selecter::separateBW(myImage *mim, float threshold, vector<myPoint> *black, vector<myPoint> *white) {
    // Separates the image between points above and points below the threshold in terms of V component
	// threshold is between 0 and 1

	myColorRGB col;
	float gray = 0;
	hsv h;

	for(int i = 0; i < mim->w; i++) {
        for(int j = 0; j < mim->h; j++) {
            col = mim->getCol(myPoint(i, j));
            h = col.col2hsv();
            gray = h.v / 255.0f;

            if(gray >= threshold) {
                white->push_back(myPoint(i, j));	
            } else {
                black->push_back(myPoint(i, j));
            }
        }
	}

}

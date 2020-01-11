#ifndef MYCIMAGE_H
#define MYCIMAGE_H

#include "myImage.h"
#include "myPoint.h"
#include "myColorRGB.h"

class myCImage : public myImage {

    public:

        unsigned char *src;
	    myCImage(unsigned char *s, int w, int h): src(s), myImage(w, h) {};
  
        myCImage(int _w, int _h) {
            w = _w;
            h = _h;
            src = (unsigned char *) malloc(sizeof(unsigned char) * w * h * 4);
            myColorRGB mywhite = myColorRGB(255, 255, 255, 255);
            for(int i = 0; i < w; i++) {
                for(int j = 0; j < h; j++) {
                    setCol(myPoint(i, j), mywhite);
                }
            }
        };

        myColorRGB getCol(myPoint point, bool wrap = true); 
        void setCol(myPoint point, myColorRGB col, bool wrap = true);
  
};

#endif

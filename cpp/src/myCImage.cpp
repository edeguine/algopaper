#include "myCImage.h"

myColorRGB myCImage::getCol(myPoint point, bool wrap) {
    // myCImage is ARGB
    if(wrap) {
        point.x = ((int) point.x) % w;
        point.y = ((int) point.y) % h;
    }

    if(inImage(point)) {
        int offset = 4 * (w * (int) point.y + (int) point.x);
        unsigned char a = src[offset];
        unsigned char r = src[offset + 1];
        unsigned char g = src[offset + 2];
        unsigned char b = src[offset + 3];

        return myColorRGB(r, g, b, a);
    } else {
        return myblack;
    }
}

void myCImage::setCol(myPoint point, myColorRGB col, bool wrap) {
    // myCImage is ARGB
    if(wrap) {
        point.x = ((int) point.x) % w;
        point.y = ((int) point.y) % h;
    }

    if(inImage(point)) {
        int offset = 4 * (((int) point.y) * w + ((int) point.x));
        src[offset] = col.a;
        src[offset + 1] = col.r;
        src[offset + 2] = col.g;
        src[offset + 3] = col.b;
    }
}


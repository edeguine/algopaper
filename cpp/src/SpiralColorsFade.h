#ifndef SPIRALCOLORSFADE_H
#define SPIRALCOLORSFADE_H

#include "JSONUtils.h"
#include "myCImage.h"
#include "myColorRGB.h"
#include "myImage.h"
#include "utilcore.h"

class SpiralColorsFade {
    public:
        static void androidSpiralColorsFade(int *pixels, int w, int h, string jparam);
        static void processSpiralColorsFade(myImage *mim, string jparam);
};

#endif

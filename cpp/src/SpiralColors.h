#ifndef SPIRALCOLORS_H
#define SPIRALCOLORS_H

#include "JSONUtils.h"
#include "myColorRGB.h"
#include "myCImage.h"
#include "myImage.h"
#include "utilcore.h"

class SpiralColors {
    public:
        static void androidSpiralColors(int *pixels, int w, int h, string jparam);
        static void processSpiralColors(myImage *mim, string jparam);
};

#endif

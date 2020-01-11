#ifndef SPIRALCOLORSFADEMULTI_H
#define SPIRALCOLORSFADEMULTI_H

#include "JSONUtils.h"
#include "myCImage.h"
#include "myColorRGB.h"
#include "myImage.h"
#include "Palettes.h"
#include "utilcore.h"

class SpiralColorsFadeMulti {
    public:
        static void androidSpiralColorsFadeMulti(int *pixels, int w, int h, string jparam);
        static void processSpiralColorsFadeMulti(myImage *mim, string jparam);
};

#endif

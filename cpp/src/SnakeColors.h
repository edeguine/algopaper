#ifndef SNAKECOLORS_H
#define SNAKECOLORS_H

#include "myCImage.h"
#include "myImage.h"
#include "myColorRGB.h"
#include "Palettes.h"
#include "SpacePartitioning.h"
#include "utilcore.h"
#include "JSONUtils.h"

class SnakeColors {
    public:
        static void androidSnakeColors(int *pixels, int w, int h, string jparam);
        static void processSnakeColors(myImage *mim, string jparam);
};

#endif

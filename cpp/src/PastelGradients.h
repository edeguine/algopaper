#ifndef PASTELGRADIENTS_H 
#define PASTELGRADIENTS_H 

#include "JSONUtils.h"
#include "myCImage.h"
#include "myColorRGB.h"
#include "myImage.h"
#include "Palettes.h"
#include "utilcore.h"

using namespace std;

class PastelGradients {
    public:
        static void androidPastelGradients(int *pixels, int w, int h, string jparam);
        static void processPastelGradients(myImage *mim, string jparam);

};


#endif

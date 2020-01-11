#ifndef UTILCORE_H
#define UTILCORE_H

#include <random>

#include "json.h"
#include "myColorRGB.h"
#include "myPoint.h"
#include "myImage.h"

#define PI 3.14159265359 

using namespace std;
using namespace nlohmann;

class utilcore {
  public:

    // JSON functions
    template<typename T>
    static T loadParam(string jstring, string paramName, T defaultValue);
    static void importPalette(string jpalette, vector<myColorRGB> *colpalette);
    static string exportPalette(vector<myColorRGB> *palette);

    // pixels functions
    static void importARGB8888(int *pixels, int w, int h, myImage *mim);
    static void exportARGB8888(myImage *mim, int *pixels, int w, int h);

    static mt19937 getMTgenerator(int seed);
    static double randomDouble(double seed, double min, double max);
    static int randomInt(int min, int max);
    static int randomInt(int min, int max, int seed);
    static int randomInt(int min, int max, mt19937 gen);
    static float randomFloat(float min, float max);
    static float randomFloat(float min, float max, mt19937 generator);
    static float randomFloat(float min, float max, int seed);
    static myPoint randomVec(myPoint topleft, myPoint bottomright);
    static myPoint randomVec(myImage *image);
};

template<typename T>
T utilcore::loadParam(string jstring, string paramName, T defaultValue) {

    T res = defaultValue;
    auto params = json::parse(jstring);
    auto it = params.find(paramName);
    if(it != params.end()) {
        res = params[paramName];
    }

    return res;
}

#endif

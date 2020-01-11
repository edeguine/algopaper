#include "utilcore.h"

void utilcore::importPalette(string jpalette, vector<myColorRGB> *colpalette) {
    // Extact color palette from JSON parameters
    // {"palette": [[A0, R0, G0, B0], [A1, R1, G1, B1]]}

    auto palette = json::parse(jpalette);
    auto jcols = palette["palette"];
    for(auto jcol: jcols) {
        colpalette->push_back(myColorRGB(jcol[1], jcol[2], jcol[3], jcol[0]));
    }
}

string utilcore::exportPalette(vector<myColorRGB> *palette) {
    // Create JSON from palette
    // {"palette": [[A0, R0, G0, B0], [A1, R1, G1, B1]]}
    json jpalette;
    json jcolors;
    for(auto c: *palette) {
        json jcol;
        jcol.push_back(c.alpha());
        jcol.push_back(c.red());
        jcol.push_back(c.green());
        jcol.push_back(c.blue());

        jcolors.push_back(jcol);
    }
    jpalette["palette"] = jcolors;
    return jpalette.dump();
}

void utilcore::importARGB8888(int *pixels, int w, int h, myImage *mim) {
    // Import a bitmap image in ARGB8888 format

    int a, r, g, b;
    myPoint p;
    myColorRGB col;
    int channels = 4;

    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            a = pixels[j * w * channels + i * channels];
            r = pixels[j * w * channels + i * channels + 1];
            g = pixels[j * w * channels + i * channels + 2];
            b = pixels[j * w * channels + i * channels + 3];
            col = myColorRGB(r, g, b, a);
            p.x = i;
            p.y = j;
            mim->setCol(p, col);
        }
    }
}

void utilcore::exportARGB8888(myImage *mim, int *pixels, int w, int h) {
    // Export an image to an ARGB8888 bitmap

    myColorRGB col;
        myPoint p;
        int channels = 4;
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
          p.x = i;
          p.y = j;
          col = mim->getCol(p);
          pixels[j * w * channels + i * channels] = (int) col.alpha();
          pixels[j * w * channels + i * channels + 1] = (int) col.red();
          pixels[j * w * channels + i * channels + 2] = (int) col.green();
          pixels[j * w * channels + i * channels + 3] = (int) col.blue();
        }
    }
}

mt19937 utilcore::getMTgenerator(int seed) {
    // Helper function to get a Mersene-Twister random generator

    srand(seed);
    random_device rd;
    mt19937 gen(rd());

    return gen;
}


int utilcore::randomInt(int min, int max) {
    srand(clock());
    random_device rd;
    mt19937 gen(rd());
    
    uniform_real_distribution<> dis(0, 1);

    return (int) (min + dis(gen) * (max - min));
}

int utilcore::randomInt(int min, int max, mt19937 gen) {
    uniform_real_distribution<> dis(0, 1);
    return (int) (min + dis(gen) * (max - min));
}

int utilcore::randomInt(int min, int max, int seed) {
    mt19937 gen(seed);
    uniform_real_distribution<> dis(0, 1);
    return (int) (min + dis(gen) * (max - min));
}

double utilcore::randomDouble(double seed, double min, double max) {
    srand(seed);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);

    return (min + dis(gen) * (max - min));
}

float utilcore::randomFloat(float min, float max) {
    srand(clock());
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);

    return (min + dis(gen) * (max - min));
}

float utilcore::randomFloat(float min, float max, mt19937 generator) {
    uniform_real_distribution<> dis(0, 1);
        
    return (min + dis(generator) * (max - min));
}

float utilcore::randomFloat(float min, float max, int seed) {
    srand(seed);
    mt19937 gen(seed);
    uniform_real_distribution<> dis(0, 1);

    return (min + dis(gen) * (max - min));
}

myPoint utilcore::randomVec(myPoint topleft, myPoint bottomright) {
    // Returns a random vector between topleft and bottomright
    srand(clock());
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);
  
    myPoint res = topleft + myPoint((int) (dis(gen)*(bottomright - topleft).x), 
        (int) (dis(gen)*(bottomright - topleft).y));
    return res;
}

#include "PastelGradients.h"

void PastelGradients::androidPastelGradients(int *pixels, int w, int h, string jparam) {

    myImage *mim;
    mim = (myImage *) new myCImage(w, h);
    utilcore::importARGB8888(pixels, w, h, mim);
    PastelGradients::processPastelGradients(mim, jparam);
    utilcore::exportARGB8888(mim, pixels, w, h);

}

void PastelGradients::processPastelGradients(myImage *im, string jparam) {
	vector<myColorRGB> palette = Palettes::Tropicals();
    

    /*
        Parameters:
            int ph  1 - 100
            int yoffset 1 - 100
            float mixperiod = 100 - 1000
    */


	int ph = JSONUtils::loadParam<int>(jparam, "ph", 10);
	int yoffset = JSONUtils::loadParam<int>(jparam, "yoffset", 10);
	float mixperiod = JSONUtils::loadParam<float>(jparam, "mixperiod", 500.0f);


	myPoint p;

	// Palette display
	for(int k = 0; k < palette.size(); k++) {
		for(int j = k * ph; j < (k + 1) * ph; j++) {
			for(int i = 0; i < im->w; i++) {
				p.x = i;
				p.y = j;
				im->setCol(p, palette.at(k));
			}
		}
	}

	// Gradients
	int cury = 0;
	myColorRGB cola, colb, colc, cold;
	cury = 0;
	vector<myColorRGB> tomix;
	vector<float> concentrations;

	// Tri color gradients
	for(int k = 0; k < palette.size(); k++) {
		for(int kk = 0; kk < palette.size(); kk++) {
			for(int kkk = 0; kkk < palette.size(); kkk++) {
				if(k != kk && k != kkk && kk != kkk) {
					for(int j = cury; j < cury + yoffset; j++) {

						cola = palette[k];
						colb = palette[kk];
						colc = palette[kkk];

						tomix.erase(tomix.begin(), tomix.end());
						tomix.push_back(cola);
						tomix.push_back(colb);
						tomix.push_back(colc);

						for(int i = 0; i < im->w; i++) {

							concentrations.erase(concentrations.begin(), concentrations.end());

							concentrations.push_back(i * 1.0f / im->w);
							concentrations.push_back((1.0f - i * 1.0f / im->w));
							concentrations.push_back(0.5f * (1.0f + sin(i * 1.0f * 2 * PI / mixperiod)) / 2.0f);

							cold = myColorRGB::cielMix(&tomix, &concentrations);

							p.x = i;
							p.y = j;

							im->setCol(p, cold);
						}
				}
				cury += yoffset;
			}
		}
	}
  }
}

#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <vector>

#include "myColorRGB.h"
#include "myPoint.h"
#include "utilcore.h"

class myImage {

	public:
		int w, h;

		myImage(): w(0), h(0) {};
		myImage(int ww, int hh): w(ww), h(hh) {};

		bool inImage(myPoint point);

        myPoint randomPoint();

		void clear();
        void clearBlack();
  
        virtual myColorRGB getCol(myPoint point, bool wrap = false) = 0;
		virtual void setCol(myPoint point, myColorRGB col, bool wrap = false) = 0;

	    void copy(myImage *ref);
};

#endif

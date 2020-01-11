#ifndef SPACEPARTITIONING_H
#define SPACEPARTITIONING_H

#include "myImage.h"
#include "myPoint.h"

class SpacePartitioning {

	public:
		static void cubesWithStripes(myImage *im, myPoint point, float xperiod, float yperiod, float zperiod, vector<float> *res);
		static void cubesWithTwists(myImage *im, myPoint point, float xperiod, float yperiod, float zperiod, vector<float> *res);
};

#endif

#include "SpacePartitioning.h"

void SpacePartitioning::cubesWithStripes(myImage *im, myPoint point, float xperiod, float yperiod, float zperiod, vector<float> *res) {

	/* 
    Partitions the space into cubes with diagonal strips
	Returns:
	 - three color indices
	 - three mixing concentrations
	*/

	int colx, coly, colz;
	float mixx, mixy, mixz;

	coly = (int) point.y / yperiod;
	mixy = point.y / yperiod - coly;
	
	colx = (int) point.x / xperiod + coly;
	mixx = point.x / xperiod + coly - colx;
	
	// up and down 
	if(((int) (point.x / xperiod)) % 2 == 0) {
		colz = (int) ((point.x + point.y) / zperiod);
		mixz = (point.x + point.y) / zperiod - colz;
	} else {
		colz = (int) (((im->h - point.y) + point.x) / zperiod);
		mixz = ((im->h - point.y) + point.x) / zperiod - colz;
	}

	res->clear();
	res->push_back(colx);
	res->push_back(coly);
	res->push_back(colz);

	res->push_back(mixx);
	res->push_back(mixy);
	res->push_back(mixz);
}

void SpacePartitioning::cubesWithTwists(myImage *im, myPoint point, float xperiod, float yperiod, float zperiod, vector<float> *res) {

	/* 
    Partitions the space into cubes with a sin variation for the third point
	Returns:
	 - three color indices
	 - three mixing concentrations
	*/

	int colx, coly, colz;
	float mixx, mixy, mixz;

	float yperiodsin, xperiodsin;

	yperiodsin = (10.0f + yperiod * (1.0f + sin(point.y * 2 * PI / 20.0f)) / 2.0f);
	xperiodsin = (10.0f + xperiod * (1.0f + sin(point.x * 2 * PI / 20.0f)) / 2.0f);
	coly = (int) point.y / yperiodsin;
	mixy = point.y / yperiodsin - coly;
	
	colx = (int) point.x / xperiodsin + coly;
	mixx = point.x / xperiodsin + coly - colx;
	
	// up and down
	if(((int) (point.x / xperiod)) % 2 == 0) {
		colz = (int) ((point.x + point.y) / zperiod);
		mixz = (point.x + point.y) / zperiod - colz;
	} else {
		colz = (int) (((im->h - point.y) + point.x) / zperiod);
		mixz = ((im->h - point.y) + point.x) / zperiod - colz;
	}

	res->clear();
	res->push_back(colx);
	res->push_back(coly);
	res->push_back(colz);

	res->push_back(mixx);
	res->push_back(mixy);
	res->push_back(mixz);
}



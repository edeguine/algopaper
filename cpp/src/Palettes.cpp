#include "Palettes.h"
#include <utilcore.h>

vector<myColorRGB> Palettes::Goldmine() {
	vector<myColorRGB> palette;
	palette.push_back(myColorRGB(209,115,19));
	palette.push_back(myColorRGB(210,19,106));
	palette.push_back(myColorRGB(175,11,191));
	palette.push_back(myColorRGB(245,200,8));
	palette.push_back(myColorRGB(235,175,1));
	palette.push_back(myColorRGB(214,96,1));
	palette.push_back(myColorRGB(198,145,9));
	palette.push_back(myColorRGB(248,208,30));
	palette.push_back(myColorRGB(253,255,0));
	palette.push_back(myColorRGB(198,186,14));
	palette.push_back(myColorRGB(187,0,193));
	palette.push_back(myColorRGB(132,38,214));
	palette.push_back(myColorRGB(40,127,188));
	palette.push_back(myColorRGB(139,12,26));
	palette.push_back(myColorRGB(210,113,220));
	palette.push_back(myColorRGB(247,209,45));
	palette.push_back(myColorRGB(30,74,177));
	palette.push_back(myColorRGB(87,29,175));
	palette.push_back(myColorRGB(37,35,155));
	palette.push_back(myColorRGB(138,101,23));

	return palette;
}

vector<myColorRGB> Palettes::HayesWhirligig() {
	vector<myColorRGB> res;
	res.push_back(myColorRGB(19, 40, 4));
	res.push_back(myColorRGB(142, 204, 239));
	res.push_back(myColorRGB(10, 18, 81));
	return res;
}

vector<myColorRGB> Palettes::HayesWoodPecker() {
	vector<myColorRGB> res;
	res.push_back(myColorRGB(234, 22, 22));
	res.push_back(myColorRGB(253, 221, 4));
	res.push_back(myColorRGB(131, 70, 193));
	return res;
}

vector<myColorRGB> Palettes::SpringBoi() {
	vector<myColorRGB> res;
	res.push_back(myColorRGB(234, 22, 22));
	res.push_back(myColorRGB(254, 221, 4));
	return res;
}

vector<myColorRGB> Palettes::Sava() {
	vector<myColorRGB> res;
	res.push_back(myColorRGB(197, 25, 73));
	res.push_back(myColorRGB(122, 197, 25));
	return res;
}

vector<myColorRGB> Palettes::YellowFrohgs() {
	vector<myColorRGB> res;
	res.push_back(myColorRGB(197, 25, 73));
	res.push_back(myColorRGB(125, 197, 25));
	res.push_back(myColorRGB(128, 196, 25));
	res.push_back(myColorRGB(129, 194, 25));
	res.push_back(myColorRGB(129, 112, 25));
	return res;
}

vector<myColorRGB> Palettes::Tropical() {
	vector<myColorRGB> res;
	res.push_back(myColorRGB(71, 175, 98));
	res.push_back(myColorRGB(241, 104, 107));
	res.push_back(myColorRGB(254, 163, 236));
	res.push_back(myColorRGB(239, 255, 100));
	return res;
}

vector<myColorRGB> Palettes::Mellow() {
	vector<myColorRGB> res;
	res.push_back(myColorRGB(117, 16, 142));
	res.push_back(myColorRGB(243, 23, 59));
	res.push_back(myColorRGB(35, 85, 244));
	res.push_back(myColorRGB(241, 193, 25));
	return res;
}

vector<myColorRGB> Palettes::Sunset() {
	vector<myColorRGB> res;
	res.push_back(myColorRGB(42, 3, 51));
	res.push_back(myColorRGB(227, 37, 0));
	res.push_back(myColorRGB(251, 253, 75));
	res.push_back(myColorRGB(213, 10, 48));
	return res;
}

vector<myColorRGB> Palettes::getRandomPalette() {
	int i = utilcore::randomInt(0, 10);
	switch(i) {
		case 0:
			return Palettes::HayesWhirligig();
			break;
		case 1:
			return Palettes::HayesWoodPecker();
			break;
		case 2:
			return Palettes::SpringBoi();
			break;
		case 3:
			return Palettes::YellowFrohgs();
			break;
		case 4:
			return Palettes::Tropical();
			break;
		case 5:
			return Palettes::Mellow();
			break;
		case 6:
			return Palettes::Sunset();
			break;
		case 7:
			return Palettes::Turmik();
			break;
		case 8:
			return Palettes::Pinkplum();
			break;
		case 9:
			return Palettes::Sugarbaby();
			break;
		case 10:
			return Palettes::Slate();
			break;
	}
	vector<myColorRGB> res;
	return res;
}

vector<myColorRGB> Palettes::Turmik() {
	vector<myColorRGB> res;
	res.push_back(myColorRGB(223, 255, 94));
	res.push_back(myColorRGB(252, 197, 68));
	res.push_back(myColorRGB(255, 126, 33));
	res.push_back(myColorRGB(255, 84, 10));
	res.push_back(myColorRGB(0, 69, 82));
	return res;
}

vector<myColorRGB> Palettes::Pinkplum() {
	vector<myColorRGB> res;
	res.push_back(myColorRGB(211, 141, 105));
	res.push_back(myColorRGB(192, 97, 101));
	res.push_back(myColorRGB(183, 75, 99));
	res.push_back(myColorRGB(86, 47, 66));
	res.push_back(myColorRGB(105, 75, 64));
	return res;
}

vector<myColorRGB> Palettes::Sugarbaby() {
	vector<myColorRGB> res;
	res.push_back(myColorRGB(225, 175, 172));
	res.push_back(myColorRGB(247, 201, 200));
	res.push_back(myColorRGB(244, 208, 216));
	res.push_back(myColorRGB(247, 222, 227));
	res.push_back(myColorRGB(242, 227, 228));
	return res;
}

vector<myColorRGB> Palettes::Slate() {
	vector<myColorRGB> res;
	res.push_back(myColorRGB(224, 224, 224));
	res.push_back(myColorRGB(184, 169, 182));
	res.push_back(myColorRGB(119, 108, 135));
	res.push_back(myColorRGB(75, 79, 107));
	res.push_back(myColorRGB(46, 38, 64));
	return res;
}

vector<myColorRGB> Palettes::Tropicals() {
	vector<myColorRGB> res;
	res.push_back(myColorRGB(170, 138, 218));
	res.push_back(myColorRGB(252, 228, 115));
	res.push_back(myColorRGB(241, 134, 169));
	res.push_back(myColorRGB(254, 168, 111));
	res.push_back(myColorRGB(121, 214, 127));
	res.push_back(myColorRGB(249, 251, 113));
	res.push_back(myColorRGB(254, 168, 111));
	return res;
}

#ifndef MYPOINT_H
#define MYPOINT_H

#define PI 3.14159265359 

#include <math.h>
#include <ostream>
#include <vector>

using namespace std;

class myPoint {

    public:

        float x, y, z;

        myPoint() {x = 0; y = 0;};
        myPoint(float _x, float _y): x(_x), y(_y) {};

        float dist(myPoint other) {
            return sqrtf((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
        }

        float distsq(myPoint other) {
            return (other.x - x) * (other.x - x) + (other.y - y) * (other.y - y);
        }

        static bool isEqual(myPoint a, myPoint b) {
            return (a.x == b.x) && (a.y == b.y);
        }


        static float angle(myPoint a, myPoint b, myPoint c);
        float dot(myPoint p);
        float L1();
        float L2();
        myPoint scale(float t);
    
        myPoint operator+(const myPoint& vec) const;
        myPoint operator-(const myPoint& vec) const;
        myPoint operator*(const float f) const;
        friend ostream& operator<<(ostream& os, const myPoint& vec);
};

#endif

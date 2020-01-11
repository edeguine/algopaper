#include "myPoint.h" 

myPoint myPoint::operator+(const myPoint& vec ) const {
	return myPoint( x + vec.x, y + vec.y);
}

 myPoint myPoint::operator-(const myPoint& vec ) const {
	return myPoint( x - vec.x, y - vec.y);
}

 myPoint myPoint::operator*(const float f) const {
	return myPoint(x * f, y * f);
}

ostream& operator<<(ostream& os, const myPoint& vec) {
	os << vec.x << ", " << vec.y;
		return os;
};

float myPoint::angle(myPoint a, myPoint b, myPoint c) {
    /*
    Value of angle BAC
    */

	float dx21 = b.x - a.x;
	float dx31 = c.x - a.x;
	float dy21 = b.y - a.y;
	float dy31 = c.y - a.y;
	float m12 = sqrt(dx21 * dx21 + dy21 * dy21);
	float m13 = sqrt(dx31 * dx31 + dy31 * dy31);
	float theta = acos((dx21 * dx31 + dy21 * dy31) / (m12 * m13));
	return theta;
}

float myPoint::dot(myPoint p) {
	return (p.x * x + p.y * y);
}

float myPoint::L1() {
    return ((fabs(x) > fabs(y)) ? fabs(x) : fabs(y));
}

float myPoint::L2() {
    return sqrtf(x * x + y * y);
}

myPoint myPoint::scale(float t) {
	return myPoint(t * x, t * y);
}


#include <cmath>
#include "DegMinSec.hpp"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI

constexpr double DEG_to_RAD = M_PI / 180.0;

// return the value in radian
double DegMinSec::asRadian()
{
    double ret = this->asDecimalDegree() * DEG_to_RAD;
    // TODO: Add your implementation code here.
    return ret;
}

double DegMinSec::asDecimalDegree()
{
    // must take into account the sign...
    double ret;
    int sign = this->degree > 0 ? 1 : -1;
    // convert to decimal degree
    ret = std::abs((double)this->degree);
    ret += this->minute / 60.0;
    ret += this->second / 3600.0;
    return sign * ret;
}

DegMinSec::DegMinSec()
{
    this->degree = 0;
    this->minute = 0;
    this->second = 0;
}

DegMinSec::DegMinSec(double decimalDegree)
{
    this->degree = std::trunc(decimalDegree);
    double minsec = std::abs((decimalDegree - this->degree) * 60);
    this->minute = std::trunc(minsec);
    this->second = (minsec - this->minute) * 60;
}

DegMinSec::DegMinSec(int degree, unsigned int minute, float second)
{
    this->degree = degree;
    this->minute = minute;
    this->second = second;
}

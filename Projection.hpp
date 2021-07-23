#pragma once

#define _USE_MATH_DEFINES // for C++
#include <cmath>

#include "DegMinSec.hpp"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI

class Projection
{
private:
public:
	bool WGS84ToWebMercator(double lattitude, double longitude, double& x, double& y);
	bool WGS84ToWebMercator(DegMinSec lattitude, DegMinSec longitude, double& x, double& y);
};

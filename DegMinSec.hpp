#pragma once
class DegMinSec
{
	int degree;
	unsigned int minute;
	float second;
public:
	DegMinSec();
	DegMinSec(double);
	DegMinSec(int, unsigned int, float);

	// return the value in radian
	double asRadian();
	double asDecimalDegree();
};


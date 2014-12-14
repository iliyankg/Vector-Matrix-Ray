#include "TVector.h"


//Constructors
/*
Constructor overloading insures flexability and usability of the class. 
Allowing the user to enter data in a way he chooses or is avaliable.
*/
TVector::TVector()
{
	XYZ[0] = 0;
	XYZ[1] = 0;
	XYZ[2] = 0;

	magnitude = 0;
}
TVector::TVector(double x, double y, double z)
{
	XYZ[0] = x;
	XYZ[1] = y;
	XYZ[2] = z;

	magnitude = 0;
}
TVector::TVector(double* xyz)
{
	XYZ[0] = *xyz;
	XYZ[1] = *(xyz+1);
	XYZ[2] = *(xyz+2);

	magnitude = 0;
}

//Destructor
TVector::~TVector()
{
}

//Getters Setters
/*
Avoyding the use of public variables means that accessing members 
of the class has to be done via the use of getters and setters.

The setters are implemented in the same logic as the constructors 
allowing for more flexability in the code.
*/
void TVector::setVec(double x, double y, double z)
{
	XYZ[0] = x;
	XYZ[1] = y;
	XYZ[2] = z;
}
void TVector::setVec(double* xyz)
{
	XYZ[0] = *xyz;
	XYZ[1] = *(xyz + 1);
	XYZ[2] = *(xyz + 2);
}

double* TVector::getVec()
{
	return XYZ;
}
double  TVector::getMagnitude()
{
	if (magnitude == 0 && (XYZ[0] != 0 || XYZ[1] != 0 || XYZ[2] != 0))
	{
		calcMagnitude();
	}
	return magnitude;
}
double* TVector::getUnit()
{
	if (XYZ[0] == 0 && XYZ[1] == 0 && XYZ[2] == 0)
	{
		unit[0] = 0;
		unit[1] = 0;
		unit[2] = 0;
	}
	else
	{
		calcUnit();
	}
	return unit;
}
double* TVector::getInvertedVec()
{
	XYZinvert[0] = -XYZ[0];
	XYZinvert[1] = -XYZ[1];
	XYZinvert[2] = -XYZ[2];
	return XYZinvert;
}

//Private Functions
/*
These functions are meant to be accessed via the getters where
a check if they have already been called will be made. This is to
increase performance by not recalculating values which have already 
been determined.
*/
void TVector::calcMagnitude()
{
	magnitude = sqrt(pow(XYZ[0], 2) + pow(XYZ[1], 2) + pow(XYZ[2], 2));
}
void TVector::calcUnit()
{
	if (magnitude == 0 && (XYZ[0] != 0 || XYZ[1] != 0 || XYZ[2] != 0))
		calcMagnitude();

	//Normalize
	for (int i = 0; i <= 2; i++)
	{
		unit[i] = XYZ[i] / magnitude;
	}
}

//TVector FRIEND FUNCTIONS
/*
Friend functions are used to make the overall use of the class easier.
Arguments of complex data types are parsed by reference. While not
very effective for standard data types it gives a slight performance
boost when using this technique on complex data types.
*/
double dotPrdct(TVector& first, TVector& second)
{
	return first.XYZ[0] * second.XYZ[0] + first.XYZ[1] * second.XYZ[1] + first.XYZ[2] * second.XYZ[2];
}
TVector crossPrdct(TVector& first, TVector& second)
{
	return TVector((first.XYZ[1] * second.XYZ[2] - first.XYZ[2] * second.XYZ[1]), (first.XYZ[2] * second.XYZ[0] - first.XYZ[0] * second.XYZ[2]), (first.XYZ[0] * second.XYZ[1] - first.XYZ[1] * second.XYZ[0]));
}

//Operator Overloads
/*
Operator overloads replace the previously used add(), subtract() friend functions. 
Again in the aim to increase ease of use later on.
*/
TVector operator+(TVector& left, TVector& right)
{
	return TVector(left.XYZ[0] + right.XYZ[0], left.XYZ[1] + right.XYZ[1], left.XYZ[2] + right.XYZ[2]);
}
TVector operator-(TVector& left, TVector& right)
{
	return TVector(left.XYZ[0] - right.XYZ[0], left.XYZ[1] - right.XYZ[1], left.XYZ[2] - right.XYZ[2]);
}
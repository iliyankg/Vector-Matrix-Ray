#pragma once
#include <math.h>

class TVector
{
	//FRIEND DECLARATIONS
	friend double dotPrdct(TVector&, TVector&);
	friend TVector crossPrdct(TVector&, TVector&);

	//Operator overloads
	friend TVector TVector::operator+(TVector& left,TVector& right);
	friend TVector TVector::operator-(TVector& left,TVector& right);

private:
	//Private variables that hold values calculated for the vector
	double XYZ[3];
	double XYZinvert[3];
	double magnitude;
	double unit[3];

	//Calculate the magnitude and unit vector when needed
	void calcMagnitude();
	void calcUnit();

	
public:
	//Constructors
	TVector();
	TVector(double, double, double);
	TVector(double*);
	
	//Destructor
	~TVector();

	//Getters Setters
	void setVec(double, double, double);
	void setVec(double*);

	//Returns a pointer to the first element in the XYZ array
	double* getVec();
	
	//Functions that act on self
	double getMagnitude();
	double* getUnit();
	double* getInvertedVec();
};


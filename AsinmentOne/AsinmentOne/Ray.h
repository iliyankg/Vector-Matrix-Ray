#pragma once
#include <string>
#include <math.h>
#include <iostream>
/*
TVector is implemented as a container and methods from
the class are used within the calculations.
*/
#include "TVector.h"

//Deffined constants are used to increase readability.
#define RAY_ORIGIN "o"
#define RAY_DIRECTION "d"

using namespace std;

class Ray
{
	//Friend functions
	/*
	As with the previous two classes parsing by reference
	is used for complex data types.
	*/
	friend double rDistR(Ray& , Ray&);
	friend double rDistP(Ray&, TVector&);

private:
	//Ray elements
	TVector origin;
	TVector direction;
	
	/*
	Utility functions used to cover the special
	cases observed in the ray to ray solutions.
	*/
	double parallelRays(Ray& one, TVector& point);
	double parallelRaysPoint(Ray& one, TVector& point);
public:
	//Constructors
	/*
	Multiple constructors increase flexability of the code and give the 
	*/
	Ray();
	Ray(string, double, double, double);
	Ray(string, double*);
	Ray(double, double, double, double, double, double);
	Ray(double*, double*);
	
	//Destructor
	~Ray();

	//Getters Setters
	void setRay(string, double, double, double);
	void setRay(string, double*);
	void setRay(double, double, double, double, double, double);
	void setRay(double*, double*);

	double* getOrigin();
	double* getDirection();	

	
};


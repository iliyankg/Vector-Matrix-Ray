#include "Ray.h"


using namespace std;

//Constructors
Ray::Ray()
{
	origin = TVector(0, 0, 0);
	direction = TVector(0, 0, 0);
}
Ray::Ray(string identifier, double x, double y, double z)
{
	if (identifier == "ORIGIN")
	{
		origin = TVector(x, y, z);
	}
	if (identifier == "DIRECTION")
	{
		direction = TVector(x, y, z);
	}
}
Ray::Ray(string identifier, double* data)
{
	if (identifier == "ORIGIN")
	{
		origin = TVector(data);
	}
	if (identifier == "DIRECTION")
	{
		direction = TVector(data);
	}
}
Ray::Ray(double xO, double yO, double zO, double xD, double yD, double zD)
{
	origin = TVector(xO, yO, zO);
	direction = TVector(xD, yD, zD);	
}
Ray::Ray(double* orgn, double* drct)
{
	origin = TVector(orgn);
	direction = TVector(drct);
}

//Destructor
Ray::~Ray()
{
}

//Getters Setters
void Ray::setRay(string identifier, double x, double y, double z)
{
	if (identifier == "ORIGIN")
	{
		origin = TVector(x, y, z);
	}
	if (identifier == "DIRECTION")
	{
		direction = TVector(x, y, z);
	}
}
void Ray::setRay(string identifier, double* data)
{
	if (identifier == "ORIGIN")
	{
		origin = TVector(data);
	}
	if (identifier == "DIRECTION")
	{
		direction = TVector(data);
	}
}
void Ray::setRay(double xO, double yO, double zO, double xD, double yD, double zD)
{
	origin = TVector(xO, yO, zO);
	direction = TVector(xD, yD, zD);
}
void Ray::setRay(double* orgn, double* drct)
{
	origin = TVector(orgn);
	direction = TVector(drct);
}

double* Ray::getOrigin()
{
	return origin.getVec();
}
double* Ray::getDirection()
{
	return direction.getVec();
}

/*
Method used in case the two rays are parallel

This method is almost the same as the distance between point and ray method however 
it lacks the check if the steps are negative. This turns it from point to ray to 
point to infinite line. 
Because the two rays are parallel it does not matter where the shortest distance
is calculated.
*/
double Ray::parallelRays(Ray& one, TVector& point)
{
	double step1 = 0.0;

	step1 = (point.getVec()[0] * one.getDirection()[0] - one.getOrigin()[0] * one.getDirection()[0] + point.getVec()[1] * one.getDirection()[1] - one.getOrigin()[1] * one.getDirection()[1] + point.getVec()[2] * one.getDirection()[2] - one.getOrigin()[2] * one.getDirection()[2]) / (pow(one.getDirection()[0], 2) + pow(one.getDirection()[1], 2) + pow(one.getDirection()[2], 2));

	TVector temp(one.getOrigin()[0] + one.getDirection()[0] * step1, one.getOrigin()[1] + one.getDirection()[1] * step1, one.getOrigin()[2] + one.getDirection()[2] * step1);

	TVector dist = temp - point;

	return dist.getMagnitude();
}

/*
This method returns the number of steps. It is used as a 
utility function in the distance between rays method.
*/
double Ray::parallelRaysPoint(Ray& one, TVector& point)
{
	return (point.getVec()[0] * one.getDirection()[0] - one.getOrigin()[0] * one.getDirection()[0] + point.getVec()[1] * one.getDirection()[1] - one.getOrigin()[1] * one.getDirection()[1] + point.getVec()[2] * one.getDirection()[2] - one.getOrigin()[2] * one.getDirection()[2]) / (pow(one.getDirection()[0], 2) + pow(one.getDirection()[1], 2) + pow(one.getDirection()[2], 2));
}

/*Distance between two rays method.*/
double rDistR(Ray& one, Ray& two)
{
	double step1 = 0.0;
	double step2 = 0.0;

	/*System of two equations with two unknowns(step1 and step2)
	|a * step1 + b * step2 = e
	|c * step1 + d * step2 = f*/

	/*Based on the method used to calculate the distance between two rays
	we manage to derive the known numbers(a, b, c, d, e and f) using the 
	coordinates of the origin and direction vector of the two Rays.*/

	double a = two.getDirection()[0] * one.getDirection()[0] + two.getDirection()[1] * one.getDirection()[1] + two.getDirection()[2] * one.getDirection()[2];
	double b = -(pow(one.getDirection()[0], 2) + pow(one.getDirection()[1], 2) + pow(one.getDirection()[2], 2));

	double c = pow(two.getDirection()[0], 2) + pow(two.getDirection()[1], 2) + pow(two.getDirection()[2], 2);
	double d = -a;
	
	double e = one.getOrigin()[0] * one.getDirection()[0] + one.getOrigin()[1] * one.getDirection()[1] + one.getOrigin()[2] * one.getDirection()[2] - two.getOrigin()[0] * one.getDirection()[0] - two.getOrigin()[1] * one.getDirection()[1] - two.getOrigin()[2] * one.getDirection()[2];
	double f = one.getOrigin()[0] * two.getDirection()[0] + one.getOrigin()[1] * two.getDirection()[1] + one.getOrigin()[2] * two.getDirection()[2] - two.getOrigin()[0] * two.getDirection()[0] - two.getOrigin()[1] * two.getDirection()[1] - two.getOrigin()[2] * two.getDirection()[2];

	/*After all constants have been calculated we calculate the determinant.
	  This is done for two reasons:
		1. To check if there is a solution
		2. To have the determinant ready when we implement "Cramer`s Rule" to solve
		   a system of two equations with two unknowns
		   If it is '0' we will be deviding by '0' which is inpossible.
		3. Because of the method used we will be deviding by the determinant. */
	double determinant = a * d - b * c;
	cout << determinant << " determinant" << endl;
	//Check for zero or many solutions based on determinant
	if (determinant != 0)
	{
		//Calculate two unknowns
		step1 = (e * d - b * f) / determinant;
		step2 = (a * f - e * c) / determinant;

		cout << "ray step1 " << step1 << endl;
		cout << "ray step2 " << step2 << endl;

		/*If steps1(2) are less than 0 that means the point where the
		line is perpendicular to the original Ray is in the oposite direction of the 
		direction vector.Which since we have an origin is inpossible.In that case we set the seps1(2) to 0
		which means that we are taking the origins of the ray.*/
		if (step1 < 0.0)
			return rDistP(one, TVector(two.getOrigin()[0], two.getOrigin()[1], two.getOrigin()[2]));
		if (step2 < 0.0)
			return rDistP(two, TVector(one.getOrigin()[0], one.getOrigin()[1], one.getOrigin()[2]));
	}
	else
	{
		/*
		If determinant is 0 then there are many solutions therefore the two rays are parallel.
		A special case when the two lines are coinciding and going away from eachother and not coinciding is
		taken into account.
		*/
		if (one.parallelRaysPoint(one, TVector(two.getOrigin()[0], two.getOrigin()[1], two.getOrigin()[2])) >= 0 || one.parallelRaysPoint(two, TVector(one.getOrigin()[0], one.getOrigin()[1], one.getOrigin()[2])) >= 0)
		{
			return one.parallelRays(one, TVector(two.getOrigin()[0], two.getOrigin()[1], two.getOrigin()[2]));
		}
		else if (one.parallelRaysPoint(one, TVector(two.getOrigin()[0], two.getOrigin()[1], two.getOrigin()[2])) < 0 || one.parallelRaysPoint(two, TVector(one.getOrigin()[0], one.getOrigin()[1], one.getOrigin()[2])) < 0)
		{
			return rDistP(one, TVector(two.getOrigin()[0], two.getOrigin()[1], two.getOrigin()[2]));
		}		
	}

	/*After the two unkowns are calculated we create the two points which correspond to the 
	  vector which is perpendicular to both Rays at the same time. The values put in are derived from
	  the method used to solve the problem.*/

	TVector pointOne(one.getOrigin()[0] + one.getDirection()[0] * step2, one.getOrigin()[1] + one.getDirection()[1] * step2, one.getOrigin()[2] + one.getDirection()[2] * step2);
	TVector pointTwo(two.getOrigin()[0] + two.getDirection()[0] * step1, two.getOrigin()[1] + two.getDirection()[1] * step1, two.getOrigin()[2] + two.getDirection()[2] * step1);

	//We get the actuall vector by subtracting one point form the other.
	TVector dist = pointTwo - pointOne;

	/*The distance between the two Rays is the magnitude of the vector
	  perpendicular to set Rays*/
	return dist.getMagnitude();
}
/*Distance between point and ray method*/
double rDistP(Ray& one, TVector& point)
{
	double step1 = 0.0;
	
	step1 = (point.getVec()[0] * one.getDirection()[0] - one.getOrigin()[0] * one.getDirection()[0] + point.getVec()[1] * one.getDirection()[1] - one.getOrigin()[1] * one.getDirection()[1] + point.getVec()[2] * one.getDirection()[2] - one.getOrigin()[2] * one.getDirection()[2]) / (pow(one.getDirection()[0], 2) + pow(one.getDirection()[1], 2) + pow(one.getDirection()[2], 2));
	
	if (step1 < 0.0)
		step1 = 0.0;

	TVector temp(one.getOrigin()[0] + one.getDirection()[0] * step1, one.getOrigin()[1] + one.getDirection()[1] * step1, one.getOrigin()[2] + one.getDirection()[2] * step1);
	
	TVector dist = temp - point;

	return dist.getMagnitude();
}



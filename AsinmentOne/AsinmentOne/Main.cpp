#include <iostream>
#include <math.h>
#include <vector>
#include "TVector.h"
#include "Tmatrix.h"
#include "Ray.h"


typedef vector < vector < double > > vector2d;

using namespace std;

int main()
{
	//===================VECTOR TEST===================//
	/*	
	Imput values as follows! 
	
	TVector example(x, y, z);
	*/
	TVector oneV(1,0,0);
	TVector twoV(1, 1, 0);
	
	cout << "=======================================VECTOR==================================" << endl;
	cout << endl;
	
	
	TVector crossProduct = crossPrdct(oneV, twoV);
	TVector additionV = oneV + twoV;
	TVector subtractionV = oneV - twoV;

	cout << "Magnitude of 'one' is: " << oneV.getMagnitude() << endl;
	cout << endl;

	cout << "Normalized(unit vector) of 'one' is: " << endl;
	for (int i = 0; i <= 2; i++)
	{
		cout << oneV.getUnit()[i] << endl;
	}
	cout << endl;

	cout << "The inverted vector 'one' is: " << endl;
	for (int i = 0; i <= 2; i++)
	{
		cout << oneV.getInvertedVec()[i] << endl;
	}
	cout << endl;

	cout << "Dot product of the two vectors is: " << dotPrdct(oneV, twoV) << endl;
	cout << endl;

	cout << "Cross product of the two vectors is: " << endl;
	for (int i = 0; i <= 2; i++)
	{
		cout << crossProduct.getVec()[i] << endl;
	}
	cout << endl;

	cout << "Addition of the two vectors is: " << endl;
	for (int i = 0; i <= 2; i++)
	{
		cout << additionV.getVec()[i] << endl;
	}
	cout << endl;

	cout << "Subtraction of the two vectors is: " << endl;
	for (int i = 0; i <= 2; i++)
	{
		cout << subtractionV.getVec()[i] << endl;
	}
	cout << endl;

	//=================MATRIX TEST====================//
	/*
	Imput values as follows:

	q	w	e
	
	a	s	d

	z	x	c

	Tmatrix example(q,w,e,a,s,d,z,x,c);
	*/
	Tmatrix oneM(23,18,12,3,17,21,9,44,32);
	Tmatrix twoM(8,1,4,2,8,44,2,23,2);

	cout << "=======================================MATRIX==================================" << endl;
	cout << endl;

	Tmatrix multiplicationM = oneM * twoM;
	Tmatrix additionM = oneM + twoM;
	Tmatrix subtractionM = oneM - twoM;
	
	cout << "Result of multiplication is: " << endl;
	for (int i = 0; i <= 2; ++i)
	{
		for (int j = 0; j <= 2; ++j)
		{
			cout << multiplicationM.getMat()[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Result of addition is: " << endl;
	for (int i = 0; i <= 2; ++i)
	{
		for (int j = 0; j <= 2; ++j)
		{
			cout << additionM.getMat()[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Result of subtraction is: " << endl;
	for (int i = 0; i <= 2; ++i)
	{
		for (int j = 0; j <= 2; ++j)
		{
			cout << subtractionM.getMat()[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Transposed version of 'one' is: " << endl;
	for (int i = 0; i <= 2; ++i)
	{
		for (int j = 0; j <= 2; ++j)
		{
			cout << oneM.getTrans()[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Inversed version of 'one' is: " << endl;
	for (int i = 0; i <= 2; ++i)
	{
		for (int j = 0; j <= 2; ++j)
		{
			cout << oneM.getInvers()[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//===================RAY TEST=====================//
	/*
	Input values as follows:

	Ray example(origin X, origin Y, origin Z, direction X, direction Y, direction Z);
	*/
	Ray oneR(1,1,0,1,1,0);
	Ray twoR(1,0,0,1,1,0);

	TVector point(4, 2, 6);

	cout << "=======================================RAY==================================" << endl;
	cout << endl;

	cout << "Distance between ray 'one' and ray 'two' is: " << rDistR(oneR, twoR) << endl;
	cout << endl;

	cout << "Distance between ray 'one' and 'point' is: " <<  rDistP(oneR, point) << endl;
	cout << endl;

	system("PAUSE");
	return 0;
}
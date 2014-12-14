#pragma once
#include <iostream>
#include <vector>

//For couts in cases where determinant is 0
using namespace std;

/*
The main feature used to store the matricies is a two dimentional vector container
storing variables of data type double. 

This was selected as the container of choice because it allows it self to be returned
from a function as two dimentional. An action which is very difficult to do with 
standard arrays.
A drawback of this is that when inputing values a temporary vector < double> has to be created
which then gets pushed back on the main vector.

Because of the frequent use of this a typedef is made which substitutes 
writing the whole two dimentional vector declaration with a single word "vector2d". 
This way the code looks neater easier to read and eliminates the risk of mistyping 
the container defenition.
*/
typedef vector < vector <double> > vector2d;

class Tmatrix
{
	//Operator Overloads
	friend Tmatrix Tmatrix::operator+(Tmatrix& left, Tmatrix& right);
	friend Tmatrix Tmatrix::operator-(Tmatrix& left, Tmatrix& right);
	friend Tmatrix Tmatrix::operator*(Tmatrix& left, Tmatrix& right);

private:
	//Variabes that hold the original and modified matricies.
	vector2d matrix;
	vector2d transposedMat;
	vector2d inversedMat;

	//Utility
	double determinant2(double, double, double, double);
	void transposeMat();
	void transposeInvMat();
	void inverseMat();
public:
	//Constructors
	Tmatrix();
	Tmatrix(vector2d);
	Tmatrix(double, double, double, double, double, double, double, double, double);
	
	//Destructor
	~Tmatrix();

	//Getters Setters
	void setMat(vector2d);
	void setMat(double, double, double, double, double, double, double, double, double);
	vector2d getMat();
	vector2d getTrans();
	vector2d getInvers();
};


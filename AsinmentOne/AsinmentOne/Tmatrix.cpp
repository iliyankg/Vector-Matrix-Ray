#include "Tmatrix.h"

//Constructors
/*
Overloading constructors and setters is again used in order to improve 
flexability.
*/
Tmatrix::Tmatrix()
{
	vector<double> temp;
	for (int i = 0; i <= 2; i++)
	{
		temp.push_back(0.0);
	}
	matrix.push_back(temp);
	matrix.push_back(temp);
	matrix.push_back(temp);
}
Tmatrix::Tmatrix(vector2d num)
{
	matrix = num;
	inversedMat.clear();
}
Tmatrix::Tmatrix(double q, double w, double e, double a, double s, double d, double z, double x, double c)
{
	vector<double> temp;
	
	/*Populating the matrix with the input values.*/
	temp.push_back(q);
	temp.push_back(a);
	temp.push_back(z);
	matrix.push_back(temp);
	temp.clear();
	
	temp.push_back(w);
	temp.push_back(s);
	temp.push_back(x);
	matrix.push_back(temp);
	temp.clear();
	
	temp.push_back(e);
	temp.push_back(d);
	temp.push_back(c);
	matrix.push_back(temp);
	temp.clear();
	inversedMat.clear();
}

//Destructor
Tmatrix::~Tmatrix()
{
}

//Getters Setters
void Tmatrix::setMat(vector2d num)
{
	matrix = num;
	inversedMat.clear();
}
void Tmatrix::setMat(double q, double w, double e, double a, double s, double d, double z, double x, double c)
{
	
	vector<double> temp;

	/*Populating the matrix with the input values.*/
	temp.push_back(q);
	temp.push_back(a);
	temp.push_back(z);
	matrix.push_back(temp);
	temp.clear();

	temp.push_back(w);
	temp.push_back(s);
	temp.push_back(x);
	matrix.push_back(temp);
	temp.clear();

	temp.push_back(e);
	temp.push_back(d);
	temp.push_back(c);
	matrix.push_back(temp);
	temp.clear();
	inversedMat.clear();
}

vector2d Tmatrix::getMat()
{
	return matrix;
}
vector2d Tmatrix::getTrans()
{
	transposeMat();
	return transposedMat;
}
vector2d Tmatrix::getInvers()
{
	if (inversedMat.empty())
		inverseMat();
	return inversedMat;
}

//Private Functions
/*
These functions are meant to serve as utility as well as be called in the getter functions
when needed.
*/
void Tmatrix::transposeMat()
{
	vector<double> temp1;
	vector2d temp2;
	for (int i = 0; i <= 2; i++)
	{
		for (int k = 0; k <= 2; k++)
		{
			temp1.push_back(matrix[k][i]);
		}
		temp2.push_back(temp1);
		temp1.clear();
	}
	transposedMat = temp2;
}
void Tmatrix::transposeInvMat()
{
	vector<double> temp1;
	vector2d temp2;
	for (int i = 0; i <= 2; i++)
	{
		for (int k = 0; k <= 2; k++)
		{
			temp1.push_back(inversedMat[k][i]);
		}
		temp2.push_back(temp1);
		temp1.clear();
	}
	inversedMat = temp2;
}
/*
The most difficult of all matrix manipulation methods to implement. The
inverse matrix method utelizes several of the utility functions to speed up writing
the code and make it more readable.
However the technique for calculating the inverse of a matrix was much easier to hard code
instead of coming up with a loop or a set of nested loops.
This had the potential to brake and be very difficult to debug however good planning 
and being very carefull when implementing the code insured it worked with little to no issues.
*/
void Tmatrix::inverseMat()
{	
	transposeMat();

	/*Calculate determinant and check if the matrix has an inverse.*/
	double det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1]*(matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

	if (det == 0)
	{
		cout << "Matrix has no Inverse" << endl;
	}
	else
	{
		vector<double> temp;
		vector2d inverter;

		//Populates the inverter with '1'
		for (int j = 0; j <= 2; j++)
		{
			for (int i = 0; i <= 2; i++)
			{
				temp.push_back(1);
			}
			inverter.push_back(temp);
			temp.clear();
		}
		temp.clear();

		//Changes the appropriate values in the inverter matrix to '-1'
		inverter[1][0] = -1;
		inverter[0][1] = -1;
		inverter[2][1] = -1;
		inverter[1][2] = -1;

		//Calculates the matrix based on the determinants of the corresponding to each value 2x2 matricies.
		temp.push_back(determinant2(transposedMat[1][1], transposedMat[2][1], transposedMat[1][2], transposedMat[2][2]));
		temp.push_back(determinant2(transposedMat[1][0], transposedMat[2][0], transposedMat[1][2], transposedMat[2][2]));
		temp.push_back(determinant2(transposedMat[1][0], transposedMat[2][0], transposedMat[1][1], transposedMat[2][1]));
		inversedMat.push_back(temp);
		temp.clear();

		temp.push_back(determinant2(transposedMat[0][1], transposedMat[2][1], transposedMat[0][2], transposedMat[2][2]));
		temp.push_back(determinant2(transposedMat[0][0], transposedMat[2][0], transposedMat[0][2], transposedMat[2][2]));
		temp.push_back(determinant2(transposedMat[0][0], transposedMat[2][0], transposedMat[0][1], transposedMat[2][1]));
		inversedMat.push_back(temp);
		temp.clear();

		temp.push_back(determinant2(transposedMat[0][1], transposedMat[1][1], transposedMat[0][2], transposedMat[1][2]));
		temp.push_back(determinant2(transposedMat[0][0], transposedMat[1][0], transposedMat[0][2], transposedMat[1][2]));
		temp.push_back(determinant2(transposedMat[0][0], transposedMat[1][0], transposedMat[0][1], transposedMat[1][1]));
		inversedMat.push_back(temp);
		temp.clear();

		/*
		Multiplies the current state of the inversedMat by the inverter matrix.
		The reason why the overloaded '*' operator was not used for this is because
		it would intale the creation of two new TMatrix objects. Instead of doing that 
		the multiplication function is re-created.
		*/
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				inversedMat[i][j] = inversedMat[i][j] * inverter[i][j];
			}
		}

		/*
		Getting the final inversed matrix intales deviding each value by the determinant from the start
		and then transposing it.
		*/
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				inversedMat[i][j] = inversedMat[i][j] / det;
			}
		}
	}
}
/*
Used as utility during the inverse matrix calculations.
*/
double Tmatrix::determinant2(double one, double two, double three, double four)
{
	return one*four - two*three;
}

//Operator Overloads
/*
As with the TVector class operator overloads are used in order to 
speed up coding the final program as well as increase readability.
Parsing by reference is also utilized in order to boost performance.
*/
Tmatrix operator+(Tmatrix& left, Tmatrix& right)
{
	vector<double> temp1;
	vector2d temp2;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			temp1.push_back(left.getMat()[i][j] + right.getMat()[i][j]);
		}
		temp2.push_back(temp1);
		temp1.clear();
	}
	return Tmatrix(temp2);
}
Tmatrix operator-(Tmatrix& left, Tmatrix& right)
{
	vector<double> temp1;
	vector2d temp2;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			temp1.push_back(left.getMat()[i][j] - right.getMat()[i][j]);
		}
		temp2.push_back(temp1);
		temp1.clear();
	}
	return Tmatrix(temp2);
}
Tmatrix operator*(Tmatrix& left, Tmatrix& right)
{
	vector<double> temp1;
	vector2d temp2;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			double sum = 0;
			for (int k = 0; k <= 2; k++)
			{
				sum += left.getMat()[k][i] * right.getMat()[j][k];
			}
			temp1.push_back(sum);
		}
		temp2.push_back(temp1);
		temp1.clear();
	}
	return Tmatrix(temp2[0][0],temp2[0][1],temp2[0][2],temp2[1][0],temp2[1][1],temp2[1][2],temp2[2][0],temp2[2][1],temp2[2][2]);
}
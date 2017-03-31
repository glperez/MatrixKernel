/*
 * test.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: daeden
 */
#include <iostream>
#include "DenseMatrix.h"

using namespace std;


int main(int argv, char** argc)
{
	DenseMatrix<double>* test = new DenseMatrix<double>(2);

	DenseMatrix<double> a (2,3);
	DenseMatrix<double> b (3,2);
	DenseMatrix<double> c (2);

	// Matrix A
	// | 1 2 3 |
	// | 4 5 6 |
	a.getMat()[0][0] = 1.0;
	a.getMat()[0][1] = 2.0;
	a.getMat()[0][2] = 3.0;
	a.getMat()[1][0] = 4.0;
	a.getMat()[1][1] = 5.0;
	a.getMat()[1][2] = 6.0;

	// Matrix B
	// |  7  8 |
	// |  9 10 |
	// | 11 12 |
	b.getMat()[0][0] = 7.0;
	b.getMat()[0][1] = 8.0;
	b.getMat()[1][0] = 9.0;
	b.getMat()[1][1] = 10.0;
	b.getMat()[2][0] = 11.0;
	b.getMat()[2][1] = 12.0;

	// Matrix C
	// |  7  8 |
	// |  9 10 |
	c.getMat()[0][0] = 58.0;
	c.getMat()[0][1] = 64.0;
	c.getMat()[1][0] = 139.0;
	c.getMat()[1][1] = 154.0;

	Matrix<double>& cComputed = a * b;

	cout << "This is cComputed:\n";
	for(int i = 0; i < cComputed.getRowDim(); i++)
	{
		for(int j = 0; j < cComputed.getColDim(); j++)
			cout << " " << cComputed.getIJ(i,j);
		cout << endl;
	}

	delete test;

	return 0;
}

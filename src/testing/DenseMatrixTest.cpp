/*
 * DenseMatrixTest.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: daeden
 */

#include "DenseMatrixTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DenseMatrixTest);

DenseMatrix<double> DenseMatrixTest::a(2, 3);
DenseMatrix<double> DenseMatrixTest::b(3, 2);
DenseMatrix<double> DenseMatrixTest::c(2);

void DenseMatrixTest::setUp()
{
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

}

void DenseMatrixTest::tearDown()
{
	//delete a;
	//delete b;
	//delete c;
}

void DenseMatrixTest::matMulTest()
{

	Matrix<double>& computedC = a * b;

	CPPUNIT_ASSERT(computedC != b);
	CPPUNIT_ASSERT(computedC == c);
}
void DenseMatrixTest::matAddTest()
{
	CPPUNIT_FAIL("Not implemented yet!");
}
void DenseMatrixTest::matSubTest()
{
	CPPUNIT_FAIL("Not implemented yet!");
}

void DenseMatrixTest::matEqualityTest()
{
	CPPUNIT_FAIL("Not implemented yet!");
}

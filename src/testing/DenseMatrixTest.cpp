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
DenseMatrix<double> DenseMatrixTest::d(2);
DenseMatrix<double> DenseMatrixTest::e(2);
DenseMatrix<double> DenseMatrixTest::f(2);

void DenseMatrixTest::setUp()
{
	// Matrix A
	// | 1 2 3 |
	// | 4 5 6 |
	a[0][0] = 1.0;
	a[0][1] = 2.0;
	a[0][2] = 3.0;
	a[1][0] = 4.0;
	a[1][1] = 5.0;
	a[1][2] = 6.0;

	// Matrix B
	// | 7  8  |
	// | 9  10 |
	// | 11 12 |
	b[0][0] = 7.0;
	b[0][1] = 8.0;
	b[1][0] = 9.0;
	b[1][1] = 10.0;
	b[2][0] = 11.0;
	b[2][1] = 12.0;

	// Matrix C
	// | 58  64  |
	// | 139 154 |
	c[0][0] = 58.0;
	c[0][1] = 64.0;
	c[1][0] = 139.0;
	c[1][1] = 154.0;

	// Matrix d
	// | 7  8 |
	// | 9 10 |
	d[0][0] = 7.0;
	d[0][1] = 8.0;
	d[1][0] = 9.0;
	d[1][1] = 10.0;

	// Matrix e
	// | 51  56  |
	// | 130 144 |
	e[0][0] = 51.0;
	e[0][1] = 56.0;
	e[1][0] = 130.0;
	e[1][1] = 144.0;

	// Matrix f
	// | 65  72  |
	// | 148 164 |
	f[0][0] = 65.0;
	f[0][1] = 72.0;
	f[1][0] = 148.0;
	f[1][1] = 164.0;
}

void DenseMatrixTest::tearDown()
{
	//delete a;
	//delete b;
	//delete c;
}

// Test if two matrices are equal or not
void DenseMatrixTest::matEqualityTest()
{
	CPPUNIT_ASSERT(a != b);
	CPPUNIT_ASSERT(d != e);
	CPPUNIT_ASSERT(a == a);
	CPPUNIT_ASSERT(b == b);
}

// Tests the ability to multiply two matrices
void DenseMatrixTest::matMulTest()
{

	Matrix<double>& computedC = a * b;

	CPPUNIT_ASSERT(computedC != b);
	CPPUNIT_ASSERT(computedC == c);
}
void DenseMatrixTest::matAddTest()
{
	Matrix<double>& computedF = c + d;

	CPPUNIT_ASSERT(computedF != c);
	CPPUNIT_ASSERT(computedF != d);
	CPPUNIT_ASSERT(computedF == f);
}
// Tests the ability to subtract two matrices
void DenseMatrixTest::matSubTest()
{
	Matrix<double>& computedE = c - d;

	CPPUNIT_ASSERT(computedE != c);
	CPPUNIT_ASSERT(computedE != d);
	CPPUNIT_ASSERT(computedE == e);
}


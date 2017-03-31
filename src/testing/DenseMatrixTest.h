/*
 * MatrixTest.h
 *
 *  Created on: Mar 23, 2017
 *      Author: daeden
 */
#ifndef DENSEMATRIXTEST_H_
#define DENSEMATRIXTEST_H_

#include <cppunit/extensions/HelperMacros.h>
#include <iostream>

#include "DenseMatrix.h"

class DenseMatrixTest: public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE (DenseMatrixTest);
	CPPUNIT_TEST (matMulTest);
	CPPUNIT_TEST (matAddTest);
	CPPUNIT_TEST (matSubTest);
	CPPUNIT_TEST (matEqualityTest);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp();
	void tearDown();

	void matMulTest();
	void matAddTest();
	void matSubTest();

	void matEqualityTest();
protected:
	static DenseMatrix<double> a;
	static DenseMatrix<double> b;
	static DenseMatrix<double> c;

};

#endif /* DENSEMATRIXTEST_H_ */

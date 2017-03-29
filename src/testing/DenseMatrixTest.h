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

class MatrixTest: public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE (MatrixTest);
	CPPUNIT_TEST (MyTest);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp();
	void tearDown();

	void MyTest();
protected:
	static DenseMatrix<double> a;
	static DenseMatrix<double> b;
	static DenseMatrix<double> c;

};

#endif /* DENSEMATRIXTEST_H_ */

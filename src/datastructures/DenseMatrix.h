/*
 * Matrix.h
 *
 *  Created on: Mar 23, 2017
 *      Author: daeden
 */

#ifndef INCLUDE_MATRIX_H_
#define INCLUDE_MATRIX_H_

#include <iostream>

#include "Matrix.h"

template<class T>
class DenseMatrix : public Matrix<T>{
protected:
	T** mat;
public:

	DenseMatrix(unsigned int size);
	DenseMatrix(unsigned int row, unsigned int col);
	DenseMatrix(const DenseMatrix<T>& that);
	virtual ~DenseMatrix();

	virtual Matrix<T>& operator+(const Matrix<T>& b) const;
	virtual Matrix<T>& operator-(const Matrix<T>& b) const;
	virtual Matrix<T>& operator*(const Matrix<T>& b) const;

	T* operator[](const int i) const;

	bool operator==(const Matrix<T>& b) const;
	bool operator!=(const Matrix<T>& b) const;
	//Matrix<T>& operator=(const Matrix<T>&& that);

	//double determinant();

	T** getMat() const {
		return this->mat;
	}
};

#endif /* INCLUDE_MATRIX_H_ */

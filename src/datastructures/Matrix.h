/*
 * Matrix.h
 *
 *  Created on: Mar 26, 2017
 *      Author: daeden
 */

#ifndef MATRIX_H_
#define MATRIX_H_

template<class T>
class Matrix {
protected:
	const unsigned int rDim;
	const unsigned int cDim;
public:
	Matrix(const unsigned int size) : rDim(size), cDim(size) {}
	Matrix(const unsigned int rDim, const unsigned int cDim) : rDim(rDim), cDim(cDim) {}
	virtual ~Matrix() {}
	virtual const T& getIJ(unsigned int, unsigned int) const = 0 ;
	virtual Matrix<T>& operator+(const Matrix<T>& b) const = 0;
	virtual Matrix<T>& operator-(const Matrix<T>& b) const = 0;
	virtual Matrix<T>& operator*(const Matrix<T>& b) const = 0;

	virtual bool operator==(const Matrix<T>& b) const;
	virtual bool operator!=(const Matrix<T>& b) const;

	unsigned int getColDim() const {
		return cDim;
	}
	unsigned int getRowDim() const {
		return rDim;
	}
};

#endif /* MATRIX_H_ */

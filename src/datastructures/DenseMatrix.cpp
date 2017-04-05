/*
 * Matrix.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: daeden
 */

#include "DenseMatrix.h"

template<class T>
DenseMatrix<T>::DenseMatrix(const unsigned int size) :
		Matrix<T>(size)
{
	this->mat = new T*[size];

	for (int i = 0; i < size; i++)
		this->mat[i] = new T[size];
}

template<class T>
DenseMatrix<T>::DenseMatrix(const unsigned int row, const unsigned int col) :
		Matrix<T>(row, col)
{
	this->mat = new T*[Matrix<T>::rDim];

	for (int i = 0; i < Matrix<T>::rDim; i++)
		this->mat[i] = new T[Matrix<T>::cDim];
}

template<class T>
DenseMatrix<T>::DenseMatrix(const DenseMatrix<T>& that) :
		Matrix<T>(that.rDim, that.cDim)
{
	this->mat = new T*[Matrix<T>::rDim];

	for (int i = 0; i < Matrix<T>::rDim; i++)
		this->mat[i] = new T[Matrix<T>::cDim];

	for (int i = 0; i < Matrix<T>::rDim; i++)
		for (int j = 0; j < Matrix<T>::cDim; j++)
			this->mat[i][j] = that.mat[i][j];
}
/*
 template<class T>
 Matrix<T>& Matrix<T>::operator=(const Matrix<T>&& that)
 {
 this->cDim = that.cDim;
 this->rDim = that.rDim;

 this->mat = that.mat;

 return *this;
 }
 */

template<class T>
DenseMatrix<T>::~DenseMatrix()
{
	for (int i = 0; i < this->rDim; i++)
		delete[] this->mat[i];
	delete[] this->mat;
}

// C = A x B
template<class T>
Matrix<T>& DenseMatrix<T>::operator*(const Matrix<T>& b) const{

	if (Matrix<T>::cDim != b.getRowDim())
		throw 20;

	DenseMatrix<T>& c = *(new DenseMatrix<T>(this->rDim, b.getColDim()));

	for (int i = 0; i < this->rDim; i++)
		for (int j = 0; j < b.getColDim(); j++)
			for (int k = 0; k < Matrix<T>::cDim; k++)
				c[i][j] += mat[i][k]*b[k][j];

	return c;
}

// C = a - b
template<class T>
Matrix<T>& DenseMatrix<T>::operator-(const Matrix<T>& b) const
{
	if (this->cDim != b.getColDim() || this->rDim != b.getRowDim())
		throw 20;

	DenseMatrix<T>& c = *(new DenseMatrix<T>(this->cDim, this->cDim));

	for (int i = 0; i < this->rDim; i++)
		for (int j = 0; j < b.getColDim(); j++)
			c[i][j] = mat[i][j] - b[i][j];

	return c;
}

// C = a + b
template<class T>
Matrix<T>& DenseMatrix<T>::operator+(const Matrix<T>& b) const
{

	if (this->cDim != b.getColDim()|| this->rDim != b.getRowDim())
		throw 20;

	DenseMatrix<T>& c = *(new DenseMatrix<T>(this->cDim, this->cDim));

	for (int i = 0; i < this->rDim; i++)
		for (int j = 0; j < b.getColDim(); j++)
			c[i][j] = mat[i][j] + b[i][j];

	return c;
}

template<class T>
bool DenseMatrix<T>::operator==(const Matrix<T>& b) const
{
	if (this->cDim != b.getColDim() || this->rDim != b.getRowDim())
		return false;

	for (int i = 0; i < this->rDim; i++)
		for (int j = 0; j < b.getColDim(); j++)
			if (mat[i][j] != b[i][j])
				return false;

	return true;
}

template<class T>
bool DenseMatrix<T>::operator!=(const Matrix<T>& b) const
{
	return !(*this == b);
	//return false;
}

template<class T>
T* DenseMatrix<T>::operator[](const int i) const
{
	if(i >= this->rDim)
		throw 30;

	return this->mat[i];
}

template class DenseMatrix<double> ;
template class DenseMatrix<float> ;
template class DenseMatrix<int> ;

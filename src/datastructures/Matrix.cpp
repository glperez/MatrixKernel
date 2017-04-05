/*
 * Matrix.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: daeden
 */

#include "Matrix.h"

template<class T>
bool Matrix<T>::operator==(const Matrix<T>& that) const
{
	if(this->cDim != that.getColDim() || this->rDim != that.getRowDim())
		return false;

	for(int i = 0; i < this->rDim; i++)
		for(int j = 0; j < this->cDim; j++)
			if((*this)[i][j] != that[i][j])
				return false;

	return true;
}
template<class T>
bool Matrix<T>::operator!=(const Matrix<T>& that) const
{
	return !(*this == that);
}

template class Matrix<double> ;
template class Matrix<float> ;
template class Matrix<int> ;


/*
 * Matrix.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: daeden
 */

#include "Matrix.h"

template<class T>
bool Matrix<T>::operator==(Matrix<T>& that)
{
	if(this->cDim != that.getColDim() || this->rDim != that.getRowDim())
		return false;

	for(int i = 0; i < this->cDim; i++)
		return true;
	return true;
}

#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix()
{
	this->nc = 0;
	this->nr = 0;
	this->Matrices = { 0 };
}

template<typename T>
Matrix<T>::Matrix(T nr, T nc)
{
	this->nr = nr;
	this->nc = nc;
	Matrices.resize(nr);
	for (auto i = 0; i < nr; ++i)
		Matrices[i].resize(nc);

}

template<typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T> >& Matrices)
{
	this->nr = Matrices.size();
	this->nc = Matrices[0].size();
	this->Matrices = Matrices;
}


template<typename T>
Matrix<T>::Matrix(const Matrix<T>& Matrices)
{
	this->nr = Matrices.nr;
	this->nc = Matrices.nc;
	this->Matrices = Matrices.Matrices;
}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T> > Matric)
{
	this->Matrices.resize(Matric.size());
	auto i = 0;
	for (const auto& row : Matric)
	{
		for (const auto& column : row)
		{
			Matrices[i].push_back(column);
		}
		++i;
	}
	//this->Matrices = Matrices;
	this->nr = Matrices.size();
	this->nc = Matrices[0].size();
}

template<typename T>
Matrix<T> Matrix<T>::multiply(const std::vector<T>& vec)
{
	Matrix<T> result(Matrices);

	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			result.Matrices[i][j] *= vec[j];
		}
	}

	return result;
}

template<typename T>
Matrix<T> Matrix<T>::multiply(const T& value)
{
	Matrix<T> result(Matrices);

	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			result.Matrices[i][j] *= value;
		}
	}

	return result;
}
template<typename T>
Matrix<T> Matrix<T>::add(const Matrix<T>& m) const // matrix addition function 
{
	Matrix<T> result(nr, nc);
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			result.Matrices[i][j] = Matrices[i][j] + m.Matrices[i][j];
		}
	}

	return result;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const std::vector<std::vector<T> > a)
{
	this->nr = a.size();
	this->nc = a[0].size();
	Matrices = a;

	return *this;
}


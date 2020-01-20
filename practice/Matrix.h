#pragma once
#include <iostream>
#include <vector>
#include <initializer_list>

template<typename T>
class Matrix
{
private:
	std::vector<std::vector<T> >Matrices;
	T nr, nc;
public:
	Matrix();
	Matrix(std::initializer_list<std::initializer_list<T> > Matric);
	Matrix(const std::vector<std::vector<T> >& Matrices);
	Matrix(T nr, T nc);
	Matrix(const Matrix<T>& Matrices);
	size_t numbers_row() const { return nr; }              // to get number of rows
	size_t numbers_column() const { return nc; }            // to get number of colomns
	Matrix<T> multiply(const std::vector<T>& vec);        // vector and Matrix multiplication
	Matrix<T> multiply(const T& value);                  // scaler multiplication 
	Matrix<T> add(const Matrix<T>& m) const;             // matrix addition function 
	Matrix<T>& operator=(const std::vector<std::vector<T> > a);
	void print()
	{
		for (auto i = 0; i < Matrices.size(); ++i)
		{
			for (auto j = 0; j < Matrices[i].size(); ++j)
			{
				std::cout << Matrices[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
};


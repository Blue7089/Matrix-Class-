
#include "Matrix.h"
#include "Matrix.cpp"




template <typename T>
Matrix<T> operator*(Matrix<T>& a, const std::vector<T>& b)
{
	return a.multiply(b);
}

template <typename T>
Matrix<T> operator+( const Matrix<T>& a, const Matrix<T>& b )
{
	return a.add(b);
}

template <typename T>
Matrix<T> operator*(Matrix<T>& a, const T& b)
{
	return a.multiply(b);
}



int main()
{

    std::vector<int> B{ 2,1,3 };
	Matrix<int> C{ {1,2,3}, {4,5,6}, {7,8,9} };
	Matrix<int> d(C);
	Matrix<int>result =  C * B;              // vector and matrix multiplication
	result.print();
	Matrix<int> result2 = C * 4;              //  scalar multiplication 
	result2.print();
	Matrix<int> result1 = d + C;             //  matrix addition 
	result1.print();

	return 0;
}



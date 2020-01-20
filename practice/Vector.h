#pragma once

template<typename T>
class Vector
{
public:
	Vector<T>(T len1 )
	{
		len = len1;
		data = new T[len];
	}
	Vector<T>(std::initializer_list<T> const &s)
	{
		data = new T[s.size()];
		int i = 0;
		for (auto it = s.begin(); it != s.end(); )
		{
			data[i] = *it;
			++it;
			++i;
		}

		len = i;

	}
	~Vector<T>()
	{
		delete[]data;
	}
	//std::initializer_list<T> data() const { return data; }

	T size()const { return len; }
	Vector<T> add( Vector<T> vec);                            //vector addition 
	Vector<T> multiply( Vector<T>& vec);						 // Vector multiplication
	Vector<T> multiply(const T& vec);								//scalar multiplication

	void print(void)
	{
		for (auto i = 0; i < len; ++i)
		{
			std::cout << data[i] << " ";
		}
		std::cout << "\n";
	}
	T& operator[] (T index) { return data[index]; }
private :
	 T len ;
	T *data;
	
	
};

template<typename T>
Vector<T> Vector<T>::add(Vector<T> vec)  
{
	if (len != vec.size())
		throw std::invalid_argument("Vector dimension is not same");
	//Vector result(vec.size());
	for (auto i = 0; i < len; ++i)
	{
		data[i] = data[i] + vec[i];
	}

	return *this;
}

template<typename T>
Vector<T> Vector<T>::multiply( Vector<T>& vec)
{
	if (len != vec.size())
		throw std::invalid_argument("Vector dimension is not same");

	for (auto i = 0; i < len; ++i)
	{
		data[i] = data[i] * vec[i];
	}

	return *this;
}
template<typename T>
Vector<T> Vector<T>::multiply(const T& vec)
{
	//if (len != vec.size())
	//	throw std::invalid_argument("Vector dimension is not same");

	for (auto i = 0; i < len; ++i)
	{
		data[i] = data[i] * vec;
	}

	return *this;
}

template<typename T>
Vector<T>operator+(Vector<T>& a, Vector<T>& b)
{
	return a.add(b);
}

template <typename T>
Vector<T> operator*(const T& b, Vector<T>& a)
{
	return a.multiply(b);
}

template <typename T>
Vector<T> operator*(Vector<T>& b, Vector<T>& a)
{
	return b.multiply(a);
}

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class dw_array
{
private:
	int** m;
	int x, y;
public:
	dw_array(int x, int y);
	~dw_array();
	class Proxy {
	public:
		Proxy(int* _array) : _array(_array) { }

		int operator[](int index) {
			return _array[index];
		}
	private:
		int* _array;
	};
	Proxy operator[](int index) {
		return Proxy(dw_array[index]);
	}
};

template <class T>
dw_array<T>::dw_array(int x, int y)
{
	this->x = x;
	this->y = y;
	m = new T* [x];
	for (int i = 0; i < x; i++)
	{
		m[i] = new T[y];
	}
}

template <class T>
dw_array<T>::~dw_array()
{
	for (int i = 0; i < x; i++)
		delete[] m[i];
	delete[] m;
}

/*T& dw_array<T>::operator[] (int a)
{
	return dw_array(m[a]);
}*/

int main()
{
	setlocale(LC_ALL, "Russian");
	auto test = dw_array<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0];
	return 0;
}
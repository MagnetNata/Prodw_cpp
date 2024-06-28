#include <iostream>
#include <vector>
using namespace std;

//Прокси для безопасного доступа к стобцам
template <class T>
class Proxy_ {
public:
	Proxy_(T* row_ptr) : row_ptr_(row_ptr) { }
	T& operator[](size_t index) {
		if (index < 0 || index >= sizeof(row_ptr_) / sizeof(*row_ptr_)) {
			throw("Не корректный размер_");
		}
		return row_ptr_[index];
	}
private:
	T* row_ptr_;
};

template <class T>
class dw_array
{
private:
	int** m;
	size_t x_, y_;
public:
	dw_array(size_t x, size_t y): x_(x), y_(y)
	{
		if (x < 1 || y < 1) {
			throw("Не корректный размер двумерного массива");
		}
		m = new T * [x];
		for (int i = 0; i < x; i++)
		{
			m[i] = new T[y];
		}
	}
	~dw_array()
	{
		for (int i = 0; i < x_; i++)
			delete[] m[i];
		delete[] m;
	}
	Proxy_<T> operator[](size_t row)
	{
		if (row < 0 || row >= x_) {
			throw("Не корректный размер");
		}
		return Proxy_<T>(m[row]);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		auto test = dw_array<int>(2, 3);
		test[0][0] = 4;
		std::cout << test[0][0];
	}
	catch (exception& ex)
	{
		std::cout << ex.what();
	}
	catch (const char* e) {
		std::cout << e << std::endl;
	}
	return 0;
}
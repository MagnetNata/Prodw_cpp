#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T kvadrat(const T& a)
{
	return a * a;
}

template <typename T>
vector <T>& kvadrat(const vector <T>& v)
{
	int kol = v.size();
	vector <int> v1(kol);
	for (int i = 0; i < kol; i++) 
		v1[i] = v[i] * v[i];
	return v1;
}

int main()
{
	try {
		setlocale(LC_ALL, "Russian");
		int a;
		vector <int> v;
		vector <int> new_v;
		int kol;
		std::cout << "Введите число" << std::endl;
		std::cin >> a;
		std::cout << "Квадрат числа " << a << " равен " << kvadrat(a) << std::endl;

		std::cout << "Введите количество чисел вектора" << std::endl;
		std::cin >> kol;
		v.resize(kol);
		new_v.resize(kol);
		std::cout << "Введите числа вектора" << std::endl;
		for (int i = 0; i < kol; i++)
			std::cin >> v[i];
		std::cout << "Квадраты чисел вектора равны " << std::endl;
		new_v = kvadrat(v);
		for (int i = 0; i < kol; i++)
			std::cout << new_v[i] << " ";
		std::cout << std::endl;
	}
	catch (exception& ex)
	{
		std::cout << ex.what();
	}
	return 0;
}
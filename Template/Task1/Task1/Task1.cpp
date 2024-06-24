#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T kvadrat(T a)
{
	return a * a;
}

template <typename T>
vector <T>& kvadrat(vector <T>& v)
{
	int kol = v.size();
	for (int i = 0; i < kol; i++) 
		v[i] = v[i] * v[i];
	return v;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	vector <int> v;
	int kol;
	std::cout << "Введите число" << std::endl;
	std::cin >> a;
	std::cout << "Квадрат числа " << a << " равен " << kvadrat(a) << std::endl;

	std::cout << "Введите количество чисел вектора" << std::endl;
	std::cin >> kol;
	v.resize(kol);
	std::cout << "Введите числа вектора" << std::endl;
	for (int i = 0; i < kol; i++)
		std::cin >> v[i];
	std::cout << "Квадраты чисел вектора равны " << std::endl;
	v = kvadrat(v);
	for (int i = 0; i < kol; i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	return 0;
}
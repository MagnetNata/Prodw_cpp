#include <iostream>
#include <exception>
using namespace std;

class massiv {
private:
	int* mas;
	int kol_z = 0;
	int kol;
public:
	massiv(int kol)
	{
		this->kol = kol;
		mas = new int[kol];
	}
	void add_element(int el)
	{
		if (kol_z < kol)
		{
			mas[kol_z] = el;
			kol_z++;
		}
		else
			throw "Не могу добавить элемент. Массив заполнен";
	}
	int get_element(int nom)
	{
		if (nom >= 0 and nom < kol)
		{
			return mas[nom];
		}
		else
			throw "Не могу найти элемент. Выход за пределы массива";
	}
	bool operator = (massiv& a)
	{
		delete[] mas;
		kol = sizeof(a.mas) / sizeof(int);
		mas = new int[kol];
		for (int i = 0; i < kol; i++)
		{
			mas[i] = a.mas[i];
			kol_z++;
		}
		return true;
	}
	void vivod()
	{
		std::cout << "Массив: "<< endl;
		for (int i = 0; i < kol; i++)
		{
			std::cout<<mas[i]<<" ";
		}
		std::cout << endl;
	}
	~massiv()
	{
		delete[] mas;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		massiv arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.vivod();

		massiv new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);
		new_array.vivod();

		arr = new_array;
		arr.vivod();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (const char* e) {
		std::cout << e << std::endl;
	}
	return 0;
}
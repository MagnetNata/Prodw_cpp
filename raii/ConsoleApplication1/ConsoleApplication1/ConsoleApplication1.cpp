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
		if (nom>=0 and nom < kol)
		{
			return mas[nom];
		}
		else
			throw "Не могу найти элемент. Выход за пределы массива";
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
		massiv mas(5);
		mas.add_element(1);
		mas.add_element(4);
		mas.add_element(155);
		mas.add_element(14);
		mas.add_element(15);
		std::cout << mas.get_element(1) << std::endl;
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
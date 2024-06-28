#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class functor_sum {
	int m_sum; 
	int m_kol;
public:
	functor_sum() : m_sum{ 0 }, m_kol{ 0 } {}
	void operator()(int x) { 
		if (x % 3 == 0)
		{
			m_sum += x;
			m_kol++;
		}
	}
	int get_sum()
	{
		return m_sum;
	}
	int get_count()
	{
		return m_kol;
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<int> vec{ 4, 1, 3, 6, 25, 54 };
	functor_sum s();
	std::for_each(vec.begin(), vec.end(), s());
	std::cout << "get_sum() = " << s().get_sum() << std::endl;
	std::cout << "get_count() = " << s().get_count() << std::endl;
	return 0;
}
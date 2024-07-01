#include <iostream>
#include <set>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите количество чисел: " << std::endl;
    int kol;
    std::cin >> kol;
    std::cout << std::endl << "Введите " << kol << " чисел: " << std::endl;
    set<int, greater<int>> mas;
    for (int i = 0; i < kol; i++)
    {
        int x;
        std::cin >> x;
        mas.insert(x);
    }
    std::cout << std::endl << "Вывод: " << std::endl;
    for (const auto& elem : mas)
        std::cout << elem << std::endl;
    return 0;
}

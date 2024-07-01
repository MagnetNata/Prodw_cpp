#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm> 

using std::vector;
using std::unique;

vector<int>& func(vector<int>& a)
{
	auto it = unique(a.begin(), a.end());
	a.erase(it, a.end());
	return a;
}

int main()
{
	vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };
	sort(vec.begin(), vec.end());
	vec = func(vec);
	for (const auto& elem : vec)
		std::cout << elem << " ";
}

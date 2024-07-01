﻿#include <iostream>
#include <algorithm>
#include <vector>
#include <set> 
#include <list> 


using std::vector;

template <class T>
T print_container(T a)
{
	class T::iterator i = a.begin(); 
	while (i != a.end()) 
	{
		std::cout << *i << " ";
		i++; 
	}
	std::cout << std::endl;
	return a;
}

int main()
{
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set); // four one three two. помните почему такой порядок? :)

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list); // one, two, three, four

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector); // one, two, three, four
}
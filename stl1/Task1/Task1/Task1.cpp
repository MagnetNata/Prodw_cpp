#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool sort_map(const std::pair< char, int >& a, const std::pair< char, int >& b)
{
    return a.second > b.second;
}

void countChar(const char* str) {
    std::map<char, int> count;
    int l = strlen(str);
    for (int i = 0; i < l; i++) {
        count[str[i]]++;
    }
    std::vector< std::pair< char, int > > vec(count.begin(), count.end());
    std::sort(vec.begin(), vec.end(), sort_map);
    for (const auto kvp : vec) {
        std::cout << kvp.first << ": " << kvp.second << std::endl;
    }
}

int main() 
{
    countChar("Hello world!!");
    return 0;
}

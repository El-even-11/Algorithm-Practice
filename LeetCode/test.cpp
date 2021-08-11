#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> map;
    map[0]++;
    cout << map[0] << endl;

    return 0;
}
#include <iostream>
#include <random>
using namespace std;

int main()
{
    int x = 0x7fffffff;
    int y = 0x7fffffff;
    int z = 0x80000000;
    double dx = (double)x;
    double dy = (double)y;
    double dz = (double)z;

    cout << (dx * dy * dz == dz * dy * dx) << endl;
    return 0;
}
#include <cmath>
using namespace std;

int arrangeCoins(int n)
{
    return (sqrt(1l + 8l * n) - 1l) / 2.0;
}
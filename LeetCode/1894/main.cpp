#include <vector>
using namespace std;

int chalkReplacer(vector<int> &chalk, int k)
{
    int sum = 0;
    for (int a : chalk)
    {
        sum += a;
    }
    k %= sum;
    int index = 0;
    while (k >= chalk[index])
    {
        k -= chalk[index];
        index++;
    }
    return index;
}
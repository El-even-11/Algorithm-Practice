#include <vector>
using namespace std;

int f[40][2];

int findIntegers(int n)
{
    f[1][0] = 1;
    f[1][1] = 1;
    for (int i = 2; i < 40; i++)
    {
        f[i][0] = f[i - 1][1] + f[i - 1][0];
        f[i][1] = f[i - 1][0];
    }

    vector<int> num;
    while (n)
    {
        num.push_back(n & 1);
        n >>= 1;
    }
    int pre = 0;
    int ret = 0;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        int x = num[i];
        for (int k = 0; k < x; k++)
        {
            ret += f[i + 1][k];
        }
        if (pre == 1 && x == 1)
        {
            break;
        }
        pre = x;
        if (i == 0)
        {
            ret++;
        }
    }
    return ret;
}
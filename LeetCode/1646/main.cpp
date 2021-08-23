#include <cmath>
#include <algorithm>
using namespace std;

int a[110];

int getMaximumGenerated(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int m = 1;
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            a[i] = a[i / 2];
        }
        else
        {
            a[i] = a[i / 2] + a[i / 2 + 1];
        }
        m = max(m, a[i]);
    }

    return m;
}
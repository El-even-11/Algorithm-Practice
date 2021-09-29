#include <vector>
#include <algorithm>
using namespace std;

int findMinMoves(vector<int> &m)
{
    int sum = 0;
    int n = m.size();
    for (auto x : m)
    {
        sum += x;
    }

    if (sum % n != 0)
    {
        return -1;
    }

    int per = sum / n;

    int ret = 0;

    int l = 0;
    int r = sum;
    for (int i = 0; i < n; i++)
    {
        r -= m[i];
        int a = max(i * per - l, 0);
        int b = max((n - i - 1) * per - r, 0);
        ret = max(ret, a + b);
        l += m[i];
    }

    return ret;
}
#include <algorithm>
using namespace std;

long dp[1700];

int nthUglyNumber(int n)
{
    dp[1] = 1L;
    long factors[3] = {2L, 3L, 5L};
    int p2 = 1;
    int p3 = 1;
    int p5 = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[p2] * factors[0], min(dp[p3] * factors[1], dp[p5] * factors[2]));

        if (dp[i] == dp[p2] * factors[0])
        {
            p2++;
        }
        if (dp[i] == dp[p3] * factors[1])
        {
            p3++;
        }
        if (dp[i] == dp[p5] * factors[2])
        {
            p5++;
        }
    }
    return dp[n];
}

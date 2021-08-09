#include <vector>
#include <queue>
#include <iostream>
using namespace std;

long dp[1000010];
int nthSuperUglyNumber(int n, vector<int> &primes)
{
    dp[1] = 1L;
    vector<int> p(primes.size());

    for (int &x : p)
    {
        x = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        long min = 2147483647;

        for (int k = 0; k < primes.size(); k++)
        {
            if (min > dp[p[k]] * (long)primes[k])
            {
                min = dp[p[k]] * (long)primes[k];
            }
        }
        dp[i] = min;

        for (int k = 0; k < p.size(); k++)
        {
            if (dp[i] == dp[p[k]] * (long)primes[k])
            {
                p[k]++;
            }
        }
    }

    return dp[n];
}

int main()
{
    vector<int> primes{2, 7, 13, 19};
    nthSuperUglyNumber(12, primes);
    return 0;
}
#include <iostream>
using namespace std;

int dp[16][1 << 15];

int countArrangement(int n)
{
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int state = 0; state < (1 << n); state++)
        {
            for (int k = 1; k <= n; k++)
            {
                if ((state >> (k - 1)) & 1 == 0)
                {
                    continue;
                }
                if (k % i != 0 && i % k != 0)
                {
                    continue;
                }
                dp[i][state] += dp[i - 1][state & ~(1 << (k - 1))];
            }
        }
    }

    return dp[n][(1 << n) - 1];
}

int main(){
    cout << countArrangement(15) << endl;

    return 0;
}
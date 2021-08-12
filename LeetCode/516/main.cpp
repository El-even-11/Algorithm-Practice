#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010][1010];
int longestPalindromeSubseq(string s)
{
    int n = s.length();

    for (int len = 1; len <= n; len++)
    {
        for (int l = 0; l + len - 1 < n; l++)
        {
            int r = l + len - 1;
            if (len == 1)
            {
                dp[l][r] = 1;
            }
            else if (len == 2)
            {
                dp[l][r] = s[l] == s[r] ? 2 : 1;
            }
            else
            {
                dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
                dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + (s[l] == s[r] ? 2 : 0));
            }
        }
    }

    return dp[0][n - 1];
}
#include <string>
#include <algorithm>
using namespace std;

bool dp[1010][1010];

int countSubstrings(string s)
{
    int n = s.length();
    int cnt = 0;
    for (int len = 1; len <= n; len++)
    {
        for (int l = 0; l + len - 1 < n; l++)
        {
            int r = l + len - 1;
            if (len == 1)
            {
                dp[l][r] = true;
            }
            else if (len == 2)
            {
                dp[l][r] = s[l] == s[r];
            }
            else
            {
                dp[l][r] = dp[l + 1][r - 1] && s[l] == s[r];
            }
            cnt += dp[l][r];
        }
    }

    return cnt;
}
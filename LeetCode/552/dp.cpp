int dp[100001][2][3];
int MOD = 1e9 + 7;

int checkRecord(int n)
{
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;
    dp[0][0][1] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i][0][0] = ((dp[i - 1][0][0] + dp[i - 1][0][1]) % MOD + dp[i - 1][0][2]) % MOD;
        dp[i][0][1] = dp[i - 1][0][0];
        dp[i][0][2] = dp[i - 1][0][1];
        dp[i][1][0] = (((((dp[i - 1][0][0] + dp[i - 1][0][1]) % MOD + dp[i - 1][0][2]) % MOD + dp[i - 1][1][0]) % MOD + dp[i - 1][1][1]) % MOD + dp[i - 1][1][2]) % MOD;
        dp[i][1][1] = dp[i - 1][1][0];
        dp[i][1][2] = dp[i - 1][1][1];
    }

    int ans = 0;
    for (int a = 0; a < 2; a++)
    {
        for (int l = 0; l < 3; l++)
        {
            ans = (ans + dp[n - 1][a][l]) % MOD;
        }
    }

    return ans;
}
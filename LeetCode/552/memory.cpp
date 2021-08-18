int n;
long MOD = 1e9 + 7;
long cache[100001][2][3];

long dfs(int i, int a, int l)
{
    if (a > 1)
    {
        return 0;
    }
    if (l > 2)
    {
        return 0;
    }
    if (i == n)
    {
        return 1;
    }
    if (cache[i][a][l] != -1)
    {
        return cache[i][a][l];
    }
    cache[i][a][l] = (dfs(i + 1, a, 0) % MOD + dfs(i + 1, a + 1, 0) % MOD + dfs(i + 1, a, l + 1) % MOD) % MOD;
    return cache[i][a][l];
}

int checkRecord(int _n)
{
    n = _n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cache[i][j][k] = -1;
            }
        }
    }

    return (int)dfs(0, 0, 0);
}

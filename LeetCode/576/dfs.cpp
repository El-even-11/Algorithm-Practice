int M, N, K;
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int cache[60][60][60];
int MOD = 1e9 + 7;

int dfs(int x, int y, int k)
{
    if (x < 0 || x >= M || y < 0 || y >= N)
    {
        return 1;
    }

    if (k == 0)
    {
        return 0;
    }

    if (cache[x][y][k] != -1)
    {
        return cache[x][y][k];
    }

    int ans = 0;
    for (auto d : dirs)
    {
        int _x = x + d[0];
        int _y = y + d[1];
        ans += dfs(_x, _y, k - 1);
        ans %= MOD;
    }

    cache[x][y][k] = ans;
    return ans;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    M = m;
    N = n;
    K = maxMove;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k <= maxMove; k++)
            {
                cache[i][j][k] = -1;
            }
        }
    }

    return dfs(startRow, startColumn, maxMove);
}

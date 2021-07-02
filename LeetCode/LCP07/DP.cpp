#include <iostream>
#include <vector>
using namespace std;

int numWays(int n, vector<vector<int>> &relation, int k)
{
    int **dp = new int *[k + 1];
    for (int i = 0; i <= k; i++)
    {
        dp[i] = new int[n];
    }

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    vector<vector<int>> edges(n);
    for (int i = 0; i < relation.size(); i++)
    {
        edges[relation[i][1]].push_back(relation[i][0]);
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int all = 0;
            for (int k : edges[j])
            {
                all += dp[i - 1][k];
            }
            dp[i][j] = all;
        }
    }

    return dp[k][n - 1];
}
#include <vector>
#include <iostream>
using namespace std;

int ret = 0;

void dfs(int pos, int cnt, int n, int k, vector<vector<int>> &edges)
{
    if (pos == n - 1 && cnt == k)
    {
        ret++;
        return;
    }

    if (cnt > k)
    {
        return;
    }

    for (int i : edges[pos])
    {
        dfs(i, cnt + 1, n, k, edges);
    }
}

int numWays(int n, vector<vector<int>> &relation, int k)
{
    vector<vector<int>> edges(n);
    for (int i = 0; i < relation.size(); i++)
    {
        edges[relation[i][0]].push_back(relation[i][1]);
    }

    dfs(0, 0, n, k, edges);

    return ret;
}

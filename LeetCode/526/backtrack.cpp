#include <vector>
using namespace std;

vector<vector<int>> match;
bool vis[20];

int backtrack(int i, int n)
{
    if (i > n)
    {
        return 1;
    }

    int ans = 0;
    for (int j : match[i])
    {
        if (!vis[j])
        {
            vis[j] = true;
            ans += backtrack(i + 1, n);
            vis[j] = false;
        }
    }

    return ans;
}

int countArrangement(int n)
{
    match.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i % j == 0 || j % i == 0)
            {
                match[i].push_back(j);
            }
        }
    }

    return backtrack(1, n);
}
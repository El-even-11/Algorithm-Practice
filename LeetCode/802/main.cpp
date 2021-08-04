#include <vector>
using namespace std;

int color[10010];

bool dfs(int x, vector<vector<int>> &graph)
{
    if (color[x] > 0)
    {
        return color[x] == 2;
    }

    color[x] = 1;

    for (int i : graph[x])
    {
        if (!dfs(i, graph))
        {
            return false;
        }
    }

    color[x] = 2;

    return true;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();

    vector<int> ret;

    for (int i = 0; i < n; i++)
    {
        if (dfs(i, graph))
        {
            ret.push_back(i);
        }
    }

    return ret;
}
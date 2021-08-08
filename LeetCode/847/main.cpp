#include <vector>
#include <queue>
using namespace std;

int shortestPathLength(vector<vector<int>> &graph)
{
    int n = graph.size();

    queue<tuple<int, int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(1 << n));

    for (int i = 0; i < n; i++)
    {
        vis[i][1 << i] = true;
        q.push({i, 1 << i, 0});
    }

    while (!q.empty())
    {
        auto [cur, state, dist] = q.front();
        q.pop();

        if (state == (1 << n) - 1)
        {
            return dist;
        }

        for (int next : graph[cur])
        {
            int nextState = state | (1 << next);
            if (!vis[next][nextState])
            {
                q.push({next, nextState, dist + 1});
                vis[next][nextState] = true;
            }
        }
    }

    return 0;
}
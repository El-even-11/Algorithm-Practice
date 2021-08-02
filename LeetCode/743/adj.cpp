#include <vector>
using namespace std;

const int INF = 0x3f3f3f;
int dist[110];
bool vis[110];
int N, K;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    N = n;
    K = k;

    vector<vector<pair<int, int>>> g(110);

    for (auto &t : times)
    {
        g[t[0]].emplace_back(t[1], t[2]);
    }

    dijkstra(g);

    int ret = 0;

    for (int i = 1; i <= n; i++)
    {
        ret = max(ret, dist[i]);
    }

    return ret == INF ? -1 : ret;
}

void dijkstra(vector<vector<pair<int, int>>> &g)
{
    for (int i = 1; i <= N; i++)
    {
        dist[i] = INF;
        vis[i] = false;
    }

    dist[K] = 0;

    for (int p = 1; p <= N; p++)
    {
        int t = -1;
        for (int i = 1; i <= N; i++)
        {
            if (!vis[i] && (t == -1 || dist[t] > dist[i]))
            {
                t = i;
            }
        }

        vis[t] = true;

        for (int i = 0; i < g[t].size(); i++)
        {
            dist[g[t][i].first] = min(dist[g[t][i].first], dist[t] + g[t][i].second);
        }
    }
}
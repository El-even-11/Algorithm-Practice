#include <vector>
using namespace std;

const int INF = 0x3f3f3f;
int dist[110];
bool vis[110];
int g[110][110];
int N, K;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    N = n;
    K = k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g[i][j] = g[j][i] = (i == j ? 0 : INF);
        }
    }

    for (auto &t : times)
    {
        g[t[0]][t[1]] = t[2];
    }

    dijkstra();

    int ret = 0;

    for (int i = 1; i <= n; i++)
    {
        ret = max(ret, dist[i]);
    }

    return ret == INF ? -1 : ret;
}

void dijkstra()
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

        for (int i = 1; i <= N; i++)
        {
            dist[i] = min(dist[i], dist[t] + g[t][i]);
        }
    }
}
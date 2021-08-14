#include <vector>
using namespace std;

int k[510][510];
int match[510];

int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            k[i][preferences[i][j]] = j;
        }
    }

    for (auto p : pairs)
    {
        match[p[0]] = p[1];
        match[p[1]] = p[0];
    }

    int cnt = 0;
    for (int x = 0; x < n; x++)
    {
        int y = match[x];
        int _k = k[x][y];
        for (int i = 0; i < _k; i++)
        {
            int u = preferences[x][i];
            if (k[u][x] < k[u][match[u]])
            {
                cnt++;
                break;
            }
        }
    }

    return cnt;
}
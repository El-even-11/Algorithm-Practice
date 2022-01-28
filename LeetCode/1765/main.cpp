#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
{
    int m = isWater.size();
    int n = isWater[0].size();
    vector<vector<int>> ans(m, vector<int>(n, -1));

    queue<pair<int, int>> nodes;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isWater[i][j])
            {
                ans[i][j] = 0;
                nodes.push(pair<int, int>(i, j));
            }
        }
    }

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!nodes.empty())
    {
        int i = nodes.front().first;
        int j = nodes.front().second;
        nodes.pop();
        for (int t = 0; t < 4; t++)
        {
            int di = i + dir[t][0];
            int dj = j + dir[t][1];
            if (di >= 0 && di < m && dj >= 0 && dj < n && ans[di][dj] == -1)
            {
                ans[di][dj] = ans[i][j] + 1;
                nodes.push(pair<int, int>(di, dj));
            }
        }
    }

    return ans;
}

#include <queue>
using namespace std;

int cache[60][60];
int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    queue<pair<int, int>> q;
    int MOD = 1e9 + 7;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    q.push({startRow, startColumn});
    cache[startRow][startColumn] = 1;

    int ret = 0;
    while (maxMove--)
    {
        int size = q.size();
        while (size--)
        {
            auto [x, y] = q.front();
            q.pop();
            for (auto &d : dirs)
            {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                {
                    ret = (ret + cache[x][y]) % MOD;
                }
                else
                {
                    if (cache[nx][ny] == 0)
                    {
                        q.push({nx, ny});
                    }
                    cache[nx][ny] = (cache[nx][ny] + cache[x][y]) % MOD;
                }
            }
            cache[x][y] = 0;
        }
    }

    return ret;
}
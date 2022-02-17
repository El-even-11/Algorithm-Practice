#include <vector>
using namespace std;

class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
    {
        int dir[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1)));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j][0] = 1;
            }
        }

        for (int p = 1; p <= k; p++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (auto d : dir)
                    {
                        int nx = i + d[0];
                        int ny = j + d[1];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        {
                            continue;
                        }
                        dp[i][j][p] += dp[nx][ny][p - 1] / 8;
                    }
                }
            }
        }

        return dp[row][column][k];
    }
};
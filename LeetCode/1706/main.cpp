#include <vector>
#include <iostream>
using namespace std;

vector<int> findBall(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> ret(n);
    for (int k = 0; k < n; k++)
    {
        // j : position
        int j = k;
        for (int i = 0; i < m; i++)
        {
            if (grid[i][j] == 1)
            {
                if (j + 1 >= n || grid[i][j + 1] == -1)
                {
                    ret[k] = -1;
                    break;
                }
                j++;
            }
            else
            {
                if (j - 1 < 0 || grid[i][j - 1] == 1)
                {
                    ret[k] = -1;
                    break;
                }
                j--;
            }
        }

        if (ret[k] != -1)
        {
            ret[k] = j;
        }
    }

    return ret;
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, -1, -1},
                                {1, 1, 1, -1, -1},
                                {-1, -1, -1, 1, 1},
                                {1, 1, 1, 1, -1},
                                {-1, -1, -1, -1, -1}};
    vector<int> ret = findBall(grid);
    for (auto k : ret)
    {
        cout << k << " ";
    }

    return 0;
}
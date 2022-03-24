#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int dir[9][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 0}};

    int m;
    int n;

    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        m = img.size();
        n = img[0].size();

        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0;
                int cnt = 0;
                for (auto k : dir)
                {
                    int val = getval(i + k[0], j + k[1], img);
                    if (val >= 0)
                    {
                        sum += val;
                        cnt++;
                    }
                }
                ret[i][j] = sum / cnt;
            }
        }

        return ret;
    }

    int getval(int i, int j, vector<vector<int>> &img)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
        {
            return -1;
        }
        return img[i][j];
    }
};
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> mins(m);
        for (int i = 0; i < m; i++)
        {
            mins[i] = 0;
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] < matrix[i][mins[i]])
                {
                    mins[i] = j;
                }
            }
        }

        vector<int> ret;
        for (int a = 0; a < m; a++)
        {
            int i = 0;
            for (; i < m; i++)
            {
                if (matrix[i][mins[a]] > matrix[a][mins[a]])
                {
                    break;
                }
            }
            if (i == m)
            {
                ret.push_back(matrix[a][mins[a]]);
            }
        }

        return ret;
    }
};
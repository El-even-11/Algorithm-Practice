#include <vector>
#include <queue>
using namespace std;

class Row
{
public:
    int row;
    int cnt;

    Row(int row, int cnt)
    {
        this->row = row;
        this->cnt = cnt;
    }

    bool operator<(Row a) const
    {
        if (cnt != a.cnt)
        {
            return cnt > a.cnt;
        }

        return row > a.row;
    }

    bool operator>(Row a) const
    {
        if (cnt != a.cnt)
        {
            return cnt < a.cnt;
        }

        return row < a.row;
    }
};

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        priority_queue<Row> queue;
        for (int i = 0; i < mat.size(); i++)
        {
            int cnt = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    cnt++;
                }
            }
            queue.push(Row(i, cnt));
        }

        vector<int> ret;
        for (int i = 0; i < k; i++)
        {
            ret.push_back(queue.top().row);
            queue.pop();
        }

        return ret;
    }
};

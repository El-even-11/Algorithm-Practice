#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<int> presum(n + 1);
        presum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            presum[i] = s[i - 1] == '*' ? presum[i - 1] + 1 : presum[i - 1];
        }

        vector<int> left(n);
        for (int i = 0, l = -1; i < n; i++)
        {
            if (s[i] == '|')
            {
                l = i;
            }
            left[i] = l;
        }

        vector<int> right(n);
        for (int i = n - 1, r = -1; i >= 0; i--)
        {
            if (s[i] == '|')
            {
                r = i;
            }
            right[i] = r;
        }

        vector<int> ret;
        for (auto &q : queries)
        {
            int l = right[q[0]];
            int r = left[q[1]];
            if (l == -1 || r == -1)
            {
                ret.push_back(0);
            }
            else
            {
                ret.push_back(presum[r + 1] - presum[l]);
            }
        }

        return ret;
    }
};
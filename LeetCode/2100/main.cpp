#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        int n = security.size();
        vector<int> g(n);
        g[0] = 0;

        for (int i = 1; i < n; i++)
        {
            if (security[i] < security[i - 1])
            {
                g[i] = 1;
            }
            else if (security[i] > security[i - 1])
            {
                g[i] = -1;
            }
            else
            {
                g[i] = 0;
            }
        }

        vector<int> a(n);
        vector<int> b(n);
        a[0] = g[0] == 1 ? 1 : 0;
        b[0] = g[0] == -1 ? 1 : 0;
        for (int i = 1; i < n; i++)
        {
            a[i] = g[i] == 1 ? (a[i - 1] + 1) : (a[i - 1]);
            b[i] = g[i] == -1 ? (b[i - 1] + 1) : (b[i - 1]);
        }

        vector<int> ret;
        for (int i = time; i + time < n; i++)
        {
            int c1 = b[i] - b[i - time];
            int c2 = a[i + time] - a[i];
            if (c1 == 0 && c2 == 0)
            {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
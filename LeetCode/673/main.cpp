#include <vector>
#include <algorithm>
using namespace std;

int f[2010];
int g[2010];

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        g[i] = 1;
    }

    int ret = 1;
    int pos = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (f[j] + 1 > f[i])
                {
                    f[i] = f[j] + 1;
                    g[i] = g[j];
                }
                else if (f[j] + 1 > f[i])
                {
                    g[i] += g[j];
                }
            }
        }
        ret = f[i] > ret ? f[i] : ret;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (f[i] == ret)
        {
            ans += g[i];
        }
    }

    return ans;
}
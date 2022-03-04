#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int maxs[1000][1000];
        int mins[1000][1000];

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            maxs[i][i] = nums[i];
            mins[i][i] = nums[i];
        }

        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len <= n; i++)
            {
                maxs[i][i + len - 1] = max(maxs[i][i + len - 2], nums[i + len - 1]);
                mins[i][i + len - 1] = min(mins[i][i + len - 2], nums[i + len - 1]);
            }
        }

        long long ret = 0;
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len <= n; i++)
            {
                ret += (maxs[i][i + len - 1] - mins[i][i + len - 1]);
            }
        }

        return ret;
    }
};
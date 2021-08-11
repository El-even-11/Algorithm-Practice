#include <vector>
#include <unordered_map>
using namespace std;

int numberOfArithmeticSlices(vector<int> &nums)
{
    int n = nums.size();
    vector<unordered_map<long, int>> maps(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            long d = nums[i] * 1L - nums[j];
            maps[i][d] += (maps[j][d] + 1);
        }
    }

    int ret = -(n) * (n - 1) / 2;
    for (int i = 0; i < n; i++)
    {
        for (auto it : maps[i])
        {
            ret += it.second;
        }
    }

    return ret;
}
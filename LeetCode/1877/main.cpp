#include <vector>
#include <algorithm>
using namespace std;

int minPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int ret = 0;
    for (int i = 0; i < nums.size() / 2; i++)
    {
        ret = max(nums[i] + nums[nums.size() - 1 - i], ret);
    }

    return ret;
}

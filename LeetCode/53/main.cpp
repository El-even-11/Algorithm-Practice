#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int ret = nums[0];
    int sum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (sum < 0)
        {
            sum = 0;
        }
        sum += nums[i];
        ret = ret < sum ? sum : ret;
    }

    return ret;
}
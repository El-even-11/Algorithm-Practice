#include <vector>
#include <iostream>
using namespace std;

int numberOfArithmeticSlices(vector<int> &nums)
{

    if (nums.size() < 3)
    {
        return 0;
    }
    int k = nums[1] - nums[0];
    int len = 2;
    int ret = 0;
    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[i] - nums[i - 1] == k)
        {
            len++;
        }
        else
        {
            k = nums[i] - nums[i - 1];
            int a = 1;
            int b = len - 2;
            ret += (a + b) * (b - a + 1) / 2;
            len = 2;
        }
    }

    int a = 1;
    int b = len - 2;
    ret += (a + b) * (b - a + 1) / 2;
    return ret;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << numberOfArithmeticSlices(nums) << endl;

    return 0;
}
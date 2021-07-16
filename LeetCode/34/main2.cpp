#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target, bool lower)
{
    int l = 0;
    int r = nums.size() - 1;
    int ans = nums.size();

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] > target || (nums[mid] >= target && lower))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int rIndex = binarySearch(nums, target, false);
    int lIndex = binarySearch(nums, target, true);
    vector<int> ret;
    if (lIndex == rIndex)
    {
        ret.push_back(-1);
        ret.push_back(-1);
    }
    else
    {
        ret.push_back(lIndex);
        ret.push_back(rIndex - 1);
    }

    return ret;
}
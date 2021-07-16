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

int search(vector<int> &nums, int target)
{
    return binarySearch(nums, target, false) - binarySearch(nums, target, true);
}
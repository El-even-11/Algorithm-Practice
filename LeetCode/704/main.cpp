#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    int ret = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
        {
            ret = mid;
            break;
        }
        else if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ret;
}
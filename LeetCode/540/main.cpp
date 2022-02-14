#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid - 1] == nums[mid] && mid % 2 == 0 || nums[mid + 1] == nums[mid] && mid % 2 == 1)
            {
                r = mid - mid % 2;
            }
            else if (nums[mid - 1] == nums[mid] && mid % 2 == 1 || nums[mid + 1] == nums[mid] && mid % 2 == 0)
            {
                l = mid + mid % 2;
            }
            else
            {
                return nums[mid];
            }
        }

        return nums[l];
    }
};
#include <vector>
using namespace std;

class Solution
{
public:
    int cnt = 0;
    int max = 0;

    void backtrack(vector<int> &nums, int now, int pos)
    {
        if (pos == nums.size())
        {
            if (now == max)
            {
                cnt++;
            }
            return;
        }

        backtrack(nums, now, pos + 1);
        backtrack(nums, now | nums[pos], pos + 1);
    }

    int countMaxOrSubsets(vector<int> &nums)
    {
        max = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            max |= nums[i];
        }
        backtrack(nums, 0, 0);
        return cnt;
    }
};
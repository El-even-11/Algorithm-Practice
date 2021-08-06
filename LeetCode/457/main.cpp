#include <vector>
using namespace std;

int n;

int next(int s, int i)
{
    return ((s % n) + i + n) % n;
}

bool circularArrayLoop(vector<int> &nums)
{
    n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (!nums[i])
        {
            continue;
        }

        int slow = i;
        int fast = next(nums[i], i);

        while (slow != fast && nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(nums[fast], fast)] > 0)
        {
            slow = next(nums[slow], slow);
            fast = next(nums[fast], fast);
            fast = next(nums[fast], fast);
        }

        if (slow == fast && slow != next(nums[slow], slow))
        {
            return true;
        }

        slow = i;
        fast = next(nums[i], i);

        int pos = i;
        while (nums[pos] * nums[next(nums[pos], pos)] > 0)
        {
            nums[pos] = 0;
            pos = next(nums[pos], pos);
        }
    }

    return false;
}
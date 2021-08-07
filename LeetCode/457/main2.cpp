#include <vector>
#include <iostream>
using namespace std;

bool circularArrayLoop(vector<int> &nums)
{
    int n = nums.size();
    auto next = [&](int cur)
    {
        return ((cur + nums[cur]) % n + n) % n;
    };

    for (int i = 0; i < n; i++)
    {
        int slow = i;
        int fast = next(slow);
        int sign = nums[slow];

        while (slow != fast && sign * nums[slow] > 0 && sign * nums[fast] > 0 && sign * nums[next(fast)] > 0)
        {
            slow = next(slow);
            fast = next(next(fast));
        }

        if (slow == fast && slow != next(slow))
        {
            return true;
        }

        int pos = i;
        while (pos != slow)
        {
            int tmp = pos;
            pos = next(pos);
            nums[tmp] = 0;
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {-2, 1, -1, -2, -2};
    cout << circularArrayLoop(nums);

    return 0;
}
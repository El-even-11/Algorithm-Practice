#include <vector>
using namespace std;

bool canJump(vector<int> &nums)
{
    int farthest = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i <= farthest)
        {
            farthest = max(farthest, i + nums[i]);
        }
    }
    return farthest >= n - 1;
}

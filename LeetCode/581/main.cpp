#include <vector>
#include <algorithm>
using namespace std;

int findUnsortedSubarray(vector<int> &nums)
{
    vector<int> pre(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        pre[i] = nums[i];
    }

    sort(nums.begin(), nums.end());

    int l = 0;
    int r = nums.size() - 1;
    while (l < nums.size() && pre[l] == nums[l])
    {
        l++;
    }

    while (r >= 0 && pre[r] == nums[r])
    {
        r--;
    }

    return max(r - l + 1, 0);
}
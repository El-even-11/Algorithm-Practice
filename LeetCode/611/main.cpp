#include <vector>
#include <algorithm>
using namespace std;

int triangleNumber(vector<int> &nums)
{
    if (nums.size() < 3)
    {
        return 0;
    }

    sort(nums.begin(), nums.end());

    int cnt = 0;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            int l = j + 1;
            int r = nums.size() - 1;
            int k = nums[i] + nums[j];
            int ret = j;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (nums[mid] < k)
                {
                    l = mid + 1;
                    ret = mid;
                }
                else
                {
                    r = mid - 1;
                }
            }
            cnt += (ret - j);
        }
    }

    return cnt;
}
#include <vector>
using namespace std;

class NumArray
{
public:
    int sum[30010];
    int n;

    NumArray(vector<int> &nums)
    {
        n = nums.size();
        sum[0] = 0;
        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + nums[i];
        }
    }

    void update(int index, int val)
    {
        int pre = sum[index + 1] - sum[index];
        for (int i = index; i < n; i++)
        {
            sum[i + 1] += (val - pre);
        }
    }

    int sumRange(int left, int right)
    {
        return sum[right + 1] - sum[left];
    }
};

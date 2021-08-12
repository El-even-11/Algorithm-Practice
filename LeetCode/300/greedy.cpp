#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    vector<int> ret;
    ret.push_back(nums[0]);

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > ret[ret.size() - 1])
        {
            ret.push_back(nums[i]);
        }
        else
        {
            int index = -1;
            int l = 0;
            int r = ret.size() - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (ret[mid] < nums[i])
                {
                    index = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }

            ret[index + 1] = nums[i];
        }
    }

    return ret.size();
}


int main(){
    vector<int> nums={10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(nums) << endl;

    return 0;
}
#include <vector>
#include <iostream>
using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{
    int *cnt = new int[nums.size() + 1]{0};
    for (int i = 0; i < nums.size(); i++)
    {
        cnt[nums.at(i)]++;
    }
    vector<int> ret(2);
    for (int i = 1; i <= nums.size(); i++)
    {
        if (cnt[i] == 2)
        {
            ret[0] = i;
        }
        if (cnt[i] == 0)
        {
            ret[1] = i;
        }
    }

    return ret;
}
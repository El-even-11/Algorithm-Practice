#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        for (auto a : nums)
        {
            cnt[a]++;
        }

        int sum = 0;
        for (auto p : cnt)
        {
            if (p.second == 1)
            {
                sum += p.first;
            }
        }

        return sum;
    }
};
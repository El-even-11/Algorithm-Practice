#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int msum = 0;
        int m = rolls.size();
        for (auto i : rolls)
        {
            msum += i;
        }
        int nsum = (m + n) * mean - msum;

        vector<int> ret;
        if (nsum < n || nsum > n * 6)
        {
            return ret;
        }

        while (nsum)
        {
            int t = nsum / n;
            ret.push_back(t);
            nsum -= t;
            n--;
        }

        return ret;
    }
};
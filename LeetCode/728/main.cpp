#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ret;
        for (int i = left; i <= right; i++)
        {
            int a = i;
            while (a > 0)
            {
                if (a % 10 == 0 || i % (a % 10) != 0)
                {
                    break;
                }
                a /= 10;
            }
            if (a == 0)
            {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
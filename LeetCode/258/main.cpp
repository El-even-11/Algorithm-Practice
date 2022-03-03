#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getBits(int num)
    {
        vector<int> ret;
        while (num > 0)
        {
            ret.push_back(num % 10);
            num /= 10;
        }

        return ret;
    }

    int addDigits(int num)
    {
        while (num >= 10)
        {
            vector<int> bits = getBits(num);
            num = 0;
            for (int i : bits)
            {
                num += i;
            }
        }

        return num;
    }
};
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convertToBase7(int num)
    {
        string ret;
        if (num < 0)
        {
            ret.push_back('-');
        }

        num = abs(num);
        vector<int> digits;
        while (num > 0)
        {
            digits.push_back(num % 7);
            num /= 7;
        }

        for (int i = digits.size() - 1; i >= 0; i--)
        {
            ret.append(to_string(digits[i]));
        }

        return ret;
    }
};
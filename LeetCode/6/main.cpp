#include <string>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        string ret;
        int n = s.length();

        int K = numRows * 2 - 2;
        for (int row = 0; row < numRows; row++)
        {
            if (K - row < 0)
            {
                break;
            }
            for (int i = 0; i < n; i++)
            {
                if (i % K == row || i % K == K - row)
                {
                    ret.push_back(s[i]);
                }
            }
        }

        return ret;
    }
};
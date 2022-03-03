#include <string>
using namespace std;

class Solution
{
public:
    string nearestPalindromic(string s)
    {
        int n = s.length();
        bool already = true;

        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
            {
                already = false;
                break;
            }
        }

        if (already)
        {
            
        }

        int mid = (n + 1) / 2;
    }
};
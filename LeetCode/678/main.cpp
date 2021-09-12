#include <string>
using namespace std;

bool checkValidString(string s)
{
    int min = 0;
    int max = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            min++;
            max++;
        }
        else if (s[i] == ')')
        {
            max--;
            if (min > 0)
            {
                min--;
            }
            if (max < 0)
            {
                return false;
            }
        }
        else
        {
            if (min > 0)
            {
                min--;
            }
            max++;
        }
    }
    return min <= 0 && max >= 0;
}
#include <string>
using namespace std;

int balancedStringSplit(string s)
{
    int cnt = 0;
    int ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (cnt == 0)
        {
            ret++;
        }
    }
    return ret;
}
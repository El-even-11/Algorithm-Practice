#include <string>
using namespace std;

bool checkRecord(string s)
{
    int A = 0;
    int L = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
        {
            A++;
            L = 0;
            if (A > 1)
            {
                return false;
            }
        }
        else if (s[i] == 'L')
        {
            L++;
            if (L == 3)
            {
                return false;
            }
        }
        else
        {
            L = 0;
        }
    }

    return true;
}
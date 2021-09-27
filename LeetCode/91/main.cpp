#include <string>
using namespace std;

int f[101];

int numDecodings(string s)
{
    s = ' ' + s;

    f[0] = 1;
    for (int i = 1; i < s.length(); i++)
    {
        int a = s[i] - '0';
        int b = (s[i - 1] - '0') * 10 + a;
        if (a >= 1 && a <= 9)
        {
            f[i] = f[i - 1];
        }
        if (b >= 10 && b <= 26)
        {
            f[i] += f[i - 2];
        }
    }

    return f[s.length() - 1];
}
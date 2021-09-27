#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int f[100010];

int numDecodings(string s)
{
    s = ' ' + s;

    f[0] = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '*')
        {
            f[i] = (9 * f[i - 1]) % MOD;
            if (s[i - 1] == '*')
            {
                f[i] = (f[i] + (15 * f[i - 2]) % MOD) % MOD;
            }
            else if (s[i - 1] == '1')
            {
                f[i] = (f[i] + (9 * f[i - 2]) % MOD) % MOD;
            }
            else if (s[i - 1] == '2')
            {
                f[i] = (f[i] + (6 * f[i - 2]) % MOD) % MOD;
            }
        }
        else
        {
            if (s[i - 1] == '*')
            {
                int a = s[i] - '0';
                if (a >= 1 && a <= 9)
                {
                    f[i] = f[i - 1];
                }
                if (a == 0)
                {
                    f[i] = (f[i] + (2 * f[i - 2]) % MOD) % MOD;
                }
                else if (a >= 1 && a <= 6)
                {
                    f[i] = (f[i] + (12 * f[i - 2]) % MOD) % MOD;
                }
                else
                {
                    f[i] = (f[i] + (3 * f[i - 2]) % MOD) % MOD;
                }
            }
            else
            {
                int a = s[i] - '0';
                int b = (s[i - 1] - '0') * 10 + a;
                if (a >= 1 && a <= 9)
                {
                    f[i] = f[i - 1];
                }
                if (b >= 10 && b <= 26)
                {
                    f[i] = (f[i] + f[i - 2]) % MOD;
                }
            }
        }
    }

    return f[s.length() - 1] % MOD;
}
#include <string>
#include <iostream>
using namespace std;

string s;

int reverse(int start, int end)
{
    int i = start;
    if (end > s.length())
    {
        end = s.length();
    }
    for (; i < (start + end) / 2 && i < s.length(); i++)
    {
        char tmp = s[i];
        s[i] = s[start + end - i - 1];
        s[start + end - i - 1] = tmp;
    }
    return i;
}

string reverseStr(string _s, int k)
{
    s = _s;

    for (int i = 0;; i++)
    {
        int p = reverse(i * 2 * k, i * 2 * k + k);
        if (p >= s.length())
        {
            break;
        }
    }

    return s;
}

int main()
{
    cout << reverseStr("abcdefg", 2) << endl;

    return 0;
}
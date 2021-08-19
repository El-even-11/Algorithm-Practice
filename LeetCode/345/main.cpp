#include <string>
#include <iostream>
using namespace std;

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string reverseVowels(string s)
{
    int l = 0;
    int r = s.length() - 1;
    while (l < r)
    {
        while (!isVowel(s[l]) && l < r)
        {
            l++;
        }
        while (!isVowel(s[r]) && l < r)
        {
            r--;
        }
        if (l >= r)
        {
            return s;
        }
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }

    return s;
}

int main()
{
    cout << reverseVowels(".,") << endl;
    return 0;
}
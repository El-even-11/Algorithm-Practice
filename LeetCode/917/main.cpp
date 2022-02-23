#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (isChar(s[i]))
            {
                st.push(s[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (isChar(s[i]))
            {
                s[i] = st.top();
                st.pop();
            }
        }

        return s;
    }

    bool isChar(char c)
    {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
};
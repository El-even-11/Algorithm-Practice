#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        int lines = 0;
        int width = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (widths[s[i] - 'a'] + width > 100)
            {
                lines++;
                width = widths[s[i] - 'a'];
                continue;
            }
            width += widths[s[i] - 'a'];
        }

        return vector<int>{lines + 1, width};
    }
};
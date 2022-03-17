#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end(),
             [](string x, string y)
             {
                 if (x.size() != y.size())
                 {
                     return x.size() < y.size();
                 }
                 return x < y;
             });
        if (words[0].size() > 1)
        {
            return "";
        }
        string ret = words[0];
        unordered_set<string> set;
        set.insert(words[0]);

        int n = words.size();
        int len = 1;
        for (int i = 1; i < n; i++)
        {
            if (words[i].size() == 1)
            {
                set.insert(words[i]);
            }

            if (set.find(words[i].substr(0, words[i].size() - 1)) != set.end())
            {
                set.insert(words[i]);
                if (words[i].size() > len)
                {
                    ret = words[i];
                    len++;
                }
            }
        }

        return ret;
    }
};
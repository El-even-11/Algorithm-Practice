#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> uncommonFromSentences(string s1, string s2)
{
    vector<string> str1;
    vector<string> str2;

    int pre = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == ' ')
        {
            str1.push_back(s1.substr(pre, i - pre));
            pre = i + 1;
        }
    }

    str1.push_back(s1.substr(pre, s1.length() - pre));

    pre = 0;
    for (int i = 0; i < s2.length(); i++)
    {
        if (s2[i] == ' ')
        {
            str2.push_back(s2.substr(pre, i - pre));
            pre = i + 1;
        }
    }

    str2.push_back(s2.substr(pre, s2.length() - pre));

    unordered_map<string, int> cnt;
    for (int i = 0; i < str1.size(); i++)
    {
        cnt[str1[i]]++;
    }

    for (int i = 0; i < str2.size(); i++)
    {
        cnt[str2[i]]++;
    }

    vector<string> ans;
    for (auto kv : cnt)
    {
        if (kv.second == 1)
        {
            ans.push_back(kv.first);
        }
    }

    return ans;
}

int main()
{
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";

    vector<string> ans = uncommonFromSentences(s1, s2);
    for (auto s : ans)
    {
        cout << s << " ";
    }

    return 0;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string findLongestWord(string s, vector<string> &dictionary)
{
    int max = 0;
    string ret;

    sort(dictionary.begin(), dictionary.end());

    for (auto &dic : dictionary)
    {
        if (dic.size() > max)
        {
            int i = 0;
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == dic[i])
                {
                    i++;
                }
            }

            if (i == dic.size())
            {
                max = i;
                ret = dic;
            }
        }
    }

    return ret;
}
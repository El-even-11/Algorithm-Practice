#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    unordered_map<string, int> map;
    int n = s.length();
    for (int i = 0; i + 10 <= n; i++)
    {
        string str;
        map[str.assign(s, i, 10)]++;
    }

    vector<string> ret;
    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (it->second > 1)
        {
            ret.push_back(it->first);
        }
    }

    return ret;
}
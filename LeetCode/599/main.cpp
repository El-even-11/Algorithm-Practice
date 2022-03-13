#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> map;
        for (int i = 0; i < list1.size(); i++)
        {
            map[list1[i]] = i;
        }

        int min = 0x7fffffff;
        vector<string> ret;
        for (int i = 0; i < list2.size(); i++)
        {
            if (map.find(list2[i]) == map.end())
            {
                continue;
            }
            int j = map[list2[i]];
            if (i + j > min)
            {
                continue;
            }
            else if (i + j == min)
            {
                ret.push_back(list2[i]);
            }
            else
            {
                min = i + j;
                ret.clear();
                ret.push_back(list2[i]);
            }
        }

        return ret;
    }
};
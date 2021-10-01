#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string destCity(vector<vector<string>> &paths)
{
    unordered_set<string> set;
    for (auto &path : paths)
    {
        set.insert(path[0]);
    }

    for (auto &path : paths){
        if (!set.count(path[1])){
            return path[1];
        }
    }
    return "";
}
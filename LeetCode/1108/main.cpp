#include <string>
using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string ret;
        int n = address.size();
        for (int i = 0; i < n; i++)
        {
            if (address[i] != '.')
            {
                ret.push_back(address[i]);
            }
            else
            {
                ret.append("[.]");
            }
        }

        return ret;
    }
};
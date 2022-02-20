#include <vector>
using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int n = bits.size();
        if (n == 1)
        {
            return true;
        }

        int i = 0;
        bool isOne = false;
        while (i < n)
        {
            if (bits[i] == 1)
            {
                i += 2;
                isOne = false;
            }
            else
            {
                i++;
                isOne = true;
            }
        }

        return isOne;
    }
};
#include <string>
using namespace std;

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        bool A = true;
        int cnt = 0;
        int cntA = 0;
        int cntB = 0;

        if (colors.size() < 3)
        {
            return false;
        }
        for (int i = 0; i < colors.size(); i++)
        {
            if (colors[i] == 'A')
            {
                if (A)
                {
                    cnt++;
                }
                else
                {
                    cntB += (cnt - 2 > 0) ? (cnt - 2) : 0;
                    A = true;
                    cnt = 1;
                }
            }
            else
            {
                if (!A)
                {
                    cnt++;
                }
                else
                {
                    cntA += (cnt - 2 > 0) ? (cnt - 2) : 0;
                    A = false;
                    cnt = 1;
                }
            }
        }

        if (A)
        {
            cntA += (cnt - 2 > 0) ? (cnt - 2) : 0;
        }
        else
        {
            cntB += (cnt - 2 > 0) ? (cnt - 2) : 0;
        }

        return cntA > cntB;
    }
};
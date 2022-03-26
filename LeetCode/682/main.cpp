#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> s;
        int ret = 0;
        for (int i = 0; i < ops.size(); i++)
        {
            int now;
            if (ops[i] == "+")
            {
                int a = s.top();
                s.pop();
                now = a + s.top();
                s.push(a);
                s.push(now);
            }
            else if (ops[i] == "C")
            {
                now = -s.top();
                s.pop();
            }
            else if (ops[i] == "D")
            {
                now = 2 * s.top();
                s.push(now);
            }
            else
            {
                now = stoi(ops[i]);
                s.push(now);
            }

            ret += now;
        }

        return ret;
    }
};
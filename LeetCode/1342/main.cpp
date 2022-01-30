#include <iostream>
using namespace std;

int numberOfSteps(int num)
{
    int cnt = 0;
    while (num != 0)
    {
        cnt++;
        if (num % 2 == 0)
        {
            num /= 2;
        }
        else
        {
            num--;
        }
    }

    return cnt;
}
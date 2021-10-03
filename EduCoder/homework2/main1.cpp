#include <iostream>
using namespace std;

const int MAX = 2 * 100000010;
bool nums[MAX];

bool isPalindrome(int _n)
{
    int n = _n;
    int cnt = 0;
    int digit[20];
    while (n)
    {
        digit[cnt++] = n % 10;
        n /= 10;
    }
    for (int i = 0; i < cnt / 2; i++)
    {
        if (digit[i] != digit[cnt - i - 1])
        {
            return false;
        }
    }
    return true;
}

int primePalindrome(int n)
{

    for (int i = 2; i < MAX; i++)
    {

        if (i >= n && !nums[i] && isPalindrome(i))
        {
            return i;
        }

        if (!nums[i])
        {
            for (int j = 2; i * j < MAX; j++)
            {
                nums[i * j] = true;
            }
        }
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    cout << primePalindrome(n) << endl;
    return 0;
}
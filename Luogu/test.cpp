#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    long long int n;
    long long int num = 0, cnt = 0, tempn = 0;
    while (t--)
    {
        cin >> n;
        tempn = n;
        num = 0;
        cnt = 0;
        while (tempn != 0)
        {
            tempn /= 10;
            num = num * 10 + 1;
        }
        while (num != 1)
        {
            n %= num;
            num /= 10;
        }
        if (n == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
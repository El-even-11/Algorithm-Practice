#include <iostream>
using namespace std;

int main()
{
    int nums[10010];
    int cnt[11];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        cnt[nums[i]]++;
    }
    int a, b, c;
    a = -1;
    b = -1;
    c = -1;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target = (20 - nums[i] - nums[j]) % 10;
            cnt[nums[i]]--;
            cnt[nums[j]]--;
            target = target == 0 ? 10 : target;
            if (cnt[target] > 0)
            {
                a = nums[i];
                b = nums[j];
                c = target;
                flag = true;
                break;
            }
            cnt[nums[i]]++;
            cnt[nums[j]]++;
        }
        if (flag)
        {
            break;
        }
    }

    if (!flag)
    {
        cout << 0;
        return 0;
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += nums[i];
    }

    res -= a + b + c;

    cout << ((res % 10) == 0) ? 10 : res % 10;

    return 0;
}
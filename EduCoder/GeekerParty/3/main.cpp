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

    int res = 0;

    for (;;)
    {
        int sum = 0;
        for (int i = 1; i <= 10; i++)
        {
            sum += cnt[i];
        }

        if (sum < 3)
        {
            break;
        }

        int pre = res;
        for (int i = 1; i <= 10; i++)
        {
            for (int j = i; j <= 10; j++)
            {
                for (int k = j; k <= 10; k++)
                {
                    cnt[i]--;
                    cnt[j]--;
                    cnt[k]--;
                    if ((i + k + j) % 10 == 0 && cnt[i] >= 0 && cnt[j] >= 0 && cnt[k] >= 0)
                    {
                        res++;
                        k--;
                        continue;
                    }
                    cnt[i]++;
                    cnt[j]++;
                    cnt[k]++;
                }
            }
        }

        if (pre == res){
            break;
        }
    }

    cout << res;

    return 0;
}
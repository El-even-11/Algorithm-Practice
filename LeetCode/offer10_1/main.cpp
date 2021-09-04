int f[110];

const int MOD = 1e9 + 7;

int fib(int n)
{
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }

    return f[n];
}
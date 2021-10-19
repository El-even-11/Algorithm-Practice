#include <vector>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

/* This is the class you need to implement. *DO NOT* output anything in your code.
   We will get your answer as below:
    Newton solution(n, a);
    double answer = solution.solve();

   Feel free to add any members in the class.*/

class Newton
{
    vector<double> a;
    double aa[100];
    int n;
    const double CRITERION = 1e-6;
    const int MAX_ITERATION = 100000;

public:
    Newton(int n, vector<double> _a) : a(_a)
    {
        this->n = n;
        for (int i = n; i > 0; i--)
        {
            aa[i] = a[i] * i;
        }
    }

    double solve()
    {
        double x = 0;
        double error = 1;
        int cnt = 0;
        while (error >= CRITERION && cnt <= MAX_ITERATION)
        {
            cnt++;
            double func = 0;
            for (int i = n; i >= 0; i--)
            {
                func += a[i] * pow(x, i);
            }
            double diff_func = 0;
            for (int i = n; i > 0; i--)
            {
                diff_func += aa[i] * pow(x, i - 1);
            }
            if (diff_func == 0)
            {
                return x;
            }
            error = abs(func / diff_func);
            x = x - func / diff_func;
        }
        return x;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<double> a(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    Newton newton(n, a);
    cout << newton.solve();

    return 0;
}
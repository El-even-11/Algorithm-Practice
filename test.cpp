#include <iostream>
using namespace std;

int main()
{
    const double h = 6.626 * 1e-34;
    const double c = 3 * 1e8;
    double e;
    double p;
    double m;
    while (true)
    {
        double lambda;
        cin >> lambda;
        lambda = lambda * 1e-9;
        e = h * c / lambda;
        p = e / c;
        m = p * p / 2 / e;
        cout << e / (1.6 * 1e-19) << "eV  " << p << "kgms-1  " << m << "kg" << endl;
    }

    return 0;
}
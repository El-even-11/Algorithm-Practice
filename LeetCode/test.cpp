#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

// You can add additional standard libraries if necessary.
// Implement the Lagrange interpolation!
class Lagrange
{
public:
    Lagrange(vector<double> x, vector<double> y) : X(x), Y(y) {}

    double f(double x)
    {
        int n = X.size();
        double y = 0;
        for (int i = 0; i < n; i++)
        {
            double yn = 1;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    yn *= (x - X[j]) / (X[i] - X[j]);
                }
            }
            y += Y[i] * yn;
        }
        return y;
    }

private:
    vector<double> X, Y;
};

// Test your implementation.
int main(int argc, const char *argv[])
{
    //  Input preprocessing.
    string str;
    getline(cin, str);
    stringstream xstr(str);
    getline(cin, str);
    stringstream ystr(str);

    // X and Y are two vectors of equal length to be traversed.
    vector<double> X, Y;
    double a;
    while (xstr >> a)
        X.push_back(a);
    while (ystr >> a)
        Y.push_back(a);

    // interp_x is the point to be interpolated.
    double interp_x;
    cin >> interp_x;

    // Do Lagrange interpolation for interp_x using X and Y, and print your results
    // Note: The result retains three decimal places (rounded)!

    Lagrange l(X, Y);

    cout << fixed << setprecision(3) << l.f(interp_x) << endl;
    // End
    return 0;
}

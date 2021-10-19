#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

// Implement your Gaussian Elimination algorithm.
// You can add any standard library if needed.
//

class Gaussian
{
private:
    vector<vector<double>> mat;

public:
    Gaussian(vector<vector<double>> mat)
    {
        this->mat = mat;
    }

    void solve()
    {
        int n = mat.size();
        vector<double> b(n);
        for (int i = 0; i < n; i++)
        {
            b[i] = mat[i][n];
        }
        for (int k = 0; k < n - 1; k++)
        {
            if (!mat[k][k])
            {
                // no solution
            }
            for (int i = k + 1; i < n; i++)
            {
                double temp = mat[i][k] / mat[k][k];
                for (int j = k; j < n; j++)
                {
                    mat[i][j] = mat[i][j] - temp * mat[k][j];
                }
                b[i] = b[i] - temp * b[k];
            }
        }

        vector<double> x(n);
        if (mat[n - 1][n - 1])
        {
            cout << "No solution!";
            return;
        }
        x[n - 1] = b[n - 1] / mat[n - 1][n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            x[i] = b[i];
            for (int j = i + 1; j < n; j++)
            {
                x[i] -= mat[i][j] * x[j];
            }
            x[i] /= mat[i][i];
        }

        for (auto xx : x)
        {
            cout << fixed << setprecision(3) << xx << " ";
        }
    }
};

// Test your implementation.
int main()
{
    // Input processing.

    // Solve the linear system and print the results.
    vector<stringstream> strs;
    string str;
    while (!cin.eof())
    {
        getline(cin, str);
        strs.push_back(stringstream(str));
    }

    vector<vector<double>> mat;
    double a;
    for (int i = 0; i < strs.size(); i++)
    {
        mat.push_back(vector<double>());
        while (strs[i] >> a)
        {
            mat[i].push_back(a);
        }
    }

    Gaussian g(mat);
    g.solve();

    return 0;
}
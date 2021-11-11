#include <iostream>

using namespace std;

double exp(double x, int n, int *fakt, double *xpot)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x + 1;
    }
    else if (n > 1)
    {
        double exp_n = *xpot / *fakt; 
        return exp_n + exp(x, n - 1, ++fakt, ++xpot);
    }
}

int main()
{
    double x = 1.0;
    const int n = 3;

    int fakt[n - 1];
    double xpot[n - 1];

    fakt[n - 2] = 2;
    xpot[n - 2] = x;

    for (int i = 1; i < n - 1; i++)
    {
        fakt[n - 2 - i] = fakt[n - 1 - i] * (i + 2);
        xpot[n - 2 - i] = xpot[n - 1 - i] * x;
    }

    cout << exp(x, n, fakt, xpot);

    return 0;
}

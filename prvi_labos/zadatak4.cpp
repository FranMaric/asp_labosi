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
    double x;
    int n;

    cout << "Unesite broj x: ";
    cin >> x;
    cout << "Unesite broj n: ";
    cin >> n;

    int *fakt = (int *)malloc(n * sizeof(int));
    double *xpot = (double *)malloc(n * sizeof(double));

    double *A = (double *)malloc(n * sizeof(double));

    cout << "[";

    for (int i = 0; i < n; i++)
    {
        fakt[i - 2] = 2;
        xpot[i - 2] = x;

        for (int j = 1; j < i - 1; j++)
        {
            fakt[i - 2 - j] = fakt[i - 1 - j] * (j + 2);
            xpot[i - 2 - j] = xpot[i - 1 - j] * x;
        }

        A[i] = exp(x, i, fakt, xpot);

        cout << A[i];
        if (i != n - 1)
        {
            cout << ", ";
        }
    }

    cout << "]";

    return 0;
}

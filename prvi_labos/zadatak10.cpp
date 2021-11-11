#include <iostream>
#include<cmath>

using namespace std;

double f(double z, int k)
{
    if (k < 0)
    {
        return 0;
    }

    if (k == 0)
    {
        return z;
    }

    return (-1 * pow(z, 2) * f(z, k - 1)) / (((2 * k) + 1) * (2 * k));
}

int main()
{
    double z = 0.5;
    const int n = 5; // broj poziva funkcije

    cout << "z je konstantan = " << z;

    for (int i = 0; i < n; i++)
    {
        cout << "k = " << i << ", f = " << f(z, i) << endl;
    }

    return 0;
}
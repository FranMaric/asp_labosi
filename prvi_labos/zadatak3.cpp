#include <iostream>

using namespace std;

double pi(int n)
{
    if (n == 1)
    {
        return 4;
    }
    int sign = n % 2 == 0 ? -1 : 1;
    return pi(n - 1) + sign * 4.0 / (n * 2.0 - 1.0);
}

int main()
{
    int n;
    cout << "Unesite n: ";
    cin >> n;

    double *polje = (double *)malloc(n * sizeof(double));

    cout << "[";

    for (int i = 1; i < n + 1; i++)
    {
        *polje = pi(i);
        cout << *polje;
        if (i != n)
        {
            cout << ", ";
        }
        polje++;
    }

    cout << "]";
    
    return 0;
}
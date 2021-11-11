#include <iostream>
#include <cmath>

using namespace std;

void f(int polje[], int n, int m)
{
    if (n == 1)
    {
        polje[0] = 1;
        return;
    }
    polje[n - 1] = pow(m, n - 1);
    f(polje, n - 1, m);
}

int main()
{
    int n, m;

    cout << "Unesite broj n: ";
    cin >> n;
    cout << "Unesite broj m: ";
    cin >> m;

    int *polje = (int *)malloc(n * sizeof(int));

    f(polje, n, m);

    cout << "Izlazno polje : [";
    for (int i = 0; i < n; i++)
    {
        cout << polje[i];
        if (i != n - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
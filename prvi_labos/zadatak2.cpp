#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

bool jeKvadrat(int n)
{
    double korijen = sqrt(n);
    if (korijen == (int)korijen)
    {
        return true;
    }
    return false;
}

int zbrojiKvadrate(int polje[], int n)
{
    static int zbroj = 0;

    if (n > 0)
    {
        if (jeKvadrat(*polje))
        {
            zbroj += *polje;
        }
        zbrojiKvadrate(++polje, --n);
    }
    else
    {
        cout << " Zbroj = " << zbroj;
    }
}

int main()
{
    srand(time(NULL));


    const int n = 5;
    int polje[n];

    cout << "[";

    for (int i = 0; i < n; i++)
    {
        polje[i] = rand() % 100 + 1;
        cout << polje[i];

        if (i != n - 1)
        {
            cout << " ";
        }
    }

    cout << "]";

    zbrojiKvadrate(polje, n);

    return 0;
}
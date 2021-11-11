#include <iostream>

using namespace std;

template <typename T>
int binarnoTrazi(T polje[], int n, T x)
{
    if (n == 1)
    {
        return polje[0] == x ? 0 : -1;
    }

    int sredina = n / 2 - 1;

    if (polje[sredina] == x)
    {
        return sredina;
    }
    if (x > polje[sredina])
    {
        polje += sredina + 1;
        int next = binarnoTrazi(polje, n - sredina - 1, x);

        return next == -1 ? -1 : sredina + 1 + next;
    }
    return binarnoTrazi(polje, sredina + 1, x);
}

int main()
{
    int n;
    cout << "Unesite velicinu polja n: ";
    cin >> n;

    float x;
    cout << "Unesite broj x: ";
    cin >> x;

    float *A = (float *)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++)
    {
        A[i] = i * 1.1;
    }

    int index = binarnoTrazi<float>(A, n, x);

    if (index == -1)
    {
        cout << "Broj se ne nalazi u polju." << endl;
    }
    else
    {
        cout << "Indeks x-a: " << index << endl;
    }

    return 0;
}

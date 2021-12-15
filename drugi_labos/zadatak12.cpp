#include <iostream>

using namespace std;

class Osoba
{
public:
    unsigned int godine;
    string ime;

    Osoba() {}

    Osoba(unsigned int godine, string ime) : godine(godine), ime(ime)
    {
    }

    int operator>(Osoba other)
    {
        if (godine > other.godine)
        {
            return 1;
        }
        else
        {
            return ime > other.ime;
        }
    }

    int operator<(Osoba other)
    {
        if (godine < other.godine)
        {
            return 1;
        }
        else
        {
            return ime < other.ime;
        }
    }
};

template <class T>
void InsertionSort(T A[], int n)
{
    int i, j;
    T temp;
    for (i = 1; i < n; i++)
    {
        temp = A[i];
        for (j = i; j >= 1 && A[j - 1] > temp; j--)
            A[j] = A[j - 1];
        A[j] = temp;
    }
}

int main()
{
    Osoba osobe[] = {
        Osoba(20, "Ana"),
        Osoba(9, "Ivo"),
        Osoba(9, "Marko"),
        Osoba(22, "Lidija"),
        Osoba(19, "Pero"),
    };

    int size = sizeof(osobe) / sizeof(Osoba);

    InsertionSort<Osoba>(osobe, size);

    for (int i = 0; i < size; i++)
    {
        cout << "godina: " << osobe[i].godine << " ime: " << osobe[i].ime << endl;
    }

    return 0;
}
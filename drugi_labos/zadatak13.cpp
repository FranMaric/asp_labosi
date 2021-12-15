#include <iostream>

using namespace std;

class Vozilo
{
public:
    unsigned int godinaProizvodnje;
    string ime;

    Vozilo() {}

    Vozilo(unsigned int godinaProizvodnje, string ime) : godinaProizvodnje(godinaProizvodnje), ime(ime)
    {
    }

    int operator<(Vozilo other)
    {
        if (ime == other.ime)
        {
            return godinaProizvodnje > other.godinaProizvodnje;
        }
        return ime < other.ime;
    }
};

void Zamijeni(Vozilo &prvi, Vozilo &drugi)
{
    Vozilo temp = prvi;
    prvi = drugi;
    drugi = temp;
}

template <class T>
void SelectionSort(T A[], int n)
{
    int i, j, min;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        Zamijeni(A[i], A[min]);
    }
}

int main()
{
    Vozilo osobe[] = {
        Vozilo(1983, "Paugeot"),
        Vozilo(1981, "Paugeot"),
        Vozilo(1967, "Renault"),
        Vozilo(1972, "Fait"),
        Vozilo(1985, "BMW"),
        Vozilo(1983, "Mercedes"),
    };

    int size = sizeof(osobe) / sizeof(Vozilo);

    SelectionSort<Vozilo>(osobe, size);

    for (int i = 0; i < size; i++)
    {
        cout << "godina proizvodnje: " << osobe[i].godinaProizvodnje << " ime: " << osobe[i].ime << endl;
    }

    return 0;
}
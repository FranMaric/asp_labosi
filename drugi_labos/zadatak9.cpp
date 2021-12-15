#include <iostream>
#include <string>

using namespace std;

struct Zapis
{
    int postanskiBroj;
    string mjesto;

    Zapis() {}

    Zapis(int postanskiBroj, string mjesto) : postanskiBroj(postanskiBroj), mjesto(mjesto)
    {
    }
};

void swap(Zapis *a, Zapis *b)
{
    Zapis temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(Zapis A[], int n, char smjer)
{
    int i, j;
    Zapis temp;

    if (smjer == '0')
    {
        for (i = 1; i < n; i++)
        {
            temp = A[i];
            for (j = i; j >= 1 && A[j - 1].postanskiBroj > temp.postanskiBroj; j--)
                A[j] = A[j - 1];
            A[j] = temp;
        }
    }
    else if (smjer == '1')
    {
        for (i = 1; i < n; i++)
        {
            temp = A[i];
            for (j = i; j >= 1 && A[j - 1].postanskiBroj < temp.postanskiBroj; j--)
                A[j] = A[j - 1];
            A[j] = temp;
        }
    }
}

int main()
{
    int n;
    cout << "Upisite n: ";
    cin >> n;

    Zapis array[n], temp;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". postanski broj: ";
        cin >> temp.postanskiBroj;
        cout << i + 1 << ". mjesto: ";
        cin >> temp.mjesto;

        array[i] = temp;
    }

    char smjer;
    cout << "Smjer (0=uzlazno ili 1=silazno): ";
    cin >> smjer;

    insertionSort(array, n, smjer);

    for (int i = 0; i < n; i++)
    {
        cout << "postanski broj: " << array[i].postanskiBroj << ", mjesto: " << array[i].mjesto << endl;
    }

    return 0;
}
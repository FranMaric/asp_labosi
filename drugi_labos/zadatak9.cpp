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
    if (smjer == '0')
    {
        int min;
        for (i = 0; i < n; i++)
        {
            min = i;
            for (j = i + 1; j < n; j++)
            {
                if (A[j].postanskiBroj < A[min].postanskiBroj)
                    min = j;
            }
            swap(&A[i], &A[min]);
        }
    }
    else if (smjer == '1')
    {
        int max;
        for (i = 0; i < n; i++)
        {
            max = i;
            for (j = i + 1; j < n; j++)
            {
                if (A[j].postanskiBroj > A[max].postanskiBroj)
                    max = j;
            }
            swap(&A[i], &A[max]);
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
    cout << "Smjer (0 ili 1): ";
    cin >> smjer;

    insertionSort(array, n, smjer);

    for (int i = 0; i < n; i++)
    {
        cout << "postanski broj: " << array[i].postanskiBroj << ", mjesto: " << array[i].mjesto << endl;
    }

    return 0;
}
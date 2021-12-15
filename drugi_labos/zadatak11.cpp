#include <iostream>
#include <string>

using namespace std;

struct Zapis
{
    int brojJela;
    string nazivJela;

    Zapis() {}

    Zapis(int brojJela, string nazivJela) : brojJela(brojJela), nazivJela(nazivJela)
    {
    }
};

void swap(Zapis *a, Zapis *b)
{
    Zapis temp = *a;
    *a = *b;
    *b = temp;
}

void obicanBubbleSort(Zapis A[], int n, char smjer)
{
    int i, j;

    if (smjer == '0')
    {
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - 1 - i; j++)
            {
                if (A[j + 1].brojJela < A[j].brojJela)
                    swap(&A[j], &A[j + 1]);
            }
        }
    }
    else if (smjer == '1')
    {
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - 1 - i; j++)
            {
                if (A[j + 1].brojJela > A[j].brojJela)
                    swap(&A[j], &A[j + 1]);
            }
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
        cout << i + 1 << ". broj jela: ";
        cin >> temp.brojJela;
        cout << i + 1 << ". naziv jela: ";
        cin >> temp.nazivJela;

        array[i] = temp;
    }

    char smjer;
    cout << "Smjer (0=uzlazno ili 1=silazno): ";
    cin >> smjer;

    obicanBubbleSort(array, n, smjer);

    for (int i = 0; i < n; i++)
    {
        cout << "broj jela: " << array[i].brojJela << ", naziv jela: " << array[i].nazivJela << endl;
    }

    return 0;
}
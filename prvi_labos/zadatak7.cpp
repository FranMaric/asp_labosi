#include <iostream>
#include <time.h>

using namespace std;

template <typename T>
void swap(T *a, T *b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

// Uses Fisher–Yates shuffle [https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle]
template <typename T>
void shuffle(T *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        swap(&array[i], &array[i + rand() % (size - i)]);
    }
}

template <typename T>
void shuffleAndSquare(T *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] *= array[i];
    }
    shuffle(array, size);
}

int main()
{
    srand(time(NULL));

    int n;
    cout << "Unesite velicinu polja n: ";
    cin >> n;

    int *array = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        cout << "Unesite " << i << ". clan: ";
        cin >> array[i];
    }

    shuffleAndSquare(array, n);

    cout << "Izlazno polje: [";
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
        if (i != n - 1)
        {
            cout << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}
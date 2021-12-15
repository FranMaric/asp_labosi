#include <iostream>
#include <string>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int A[], int n, char smjer)
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
                if (A[j] < A[min])
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
                if (A[j] > A[max])
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

    int array[n];

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". broj: ";
        cin >> array[i];
    }

    char smjer;
    cout << "Smjer (0=uzlazno ili 1=silazno): ";
    cin >> smjer;

    insertionSort(array, n, smjer);

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}
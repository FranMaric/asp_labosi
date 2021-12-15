#include <iostream>
#include <string>

using namespace std;

void Zamijeni(string *prvi, string *drugi)
{
    string temp = *prvi;
    *prvi = *drugi;
    *drugi = temp;
}

void BubbleSortPoboljsani(string A[], int n, int smjer)
{
    int i, j;
    bool swapHappened = true;

    if (smjer == 1)
    {
        for (i = 0; swapHappened; i++)
        {
            swapHappened = false;
            for (j = 0; j < n - 1 - i; j++)
            {
                if (A[j + 1] < A[j])
                {
                    Zamijeni(&A[j], &A[j + 1]);
                    swapHappened = true;
                }
            }
        }
    }
    else if (smjer == 0)
    {
        for (i = 0; swapHappened; i++)
        {
            swapHappened = false;
            for (j = 0; j < n - 1 - i; j++)
            {
                if (A[j + 1] > A[j])
                {
                    Zamijeni(&A[j], &A[j + 1]);
                    swapHappened = true;
                }
            }
        }
    }
}

int main()
{
    string array[] = {
        "Ivo",
        "Marko",
        "Juraj",
        "Pero",
    };

    int size = 4;

    BubbleSortPoboljsani(array, size, 0);

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}
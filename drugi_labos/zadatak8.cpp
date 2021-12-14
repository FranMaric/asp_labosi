#include <iostream>
#include <time.h>

using namespace std;

struct Cvor
{
    int data;
    Cvor *next;
};

class Red
{
private:
    Cvor *ulaz = nullptr;
    Cvor *izlaz = nullptr;

public:
    bool dodaj(int broj)
    {
        Cvor *newElement = new (nothrow) Cvor;
        if (newElement == nullptr)
            return false;
        newElement->next = nullptr;
        newElement->data = broj;
        if (izlaz == nullptr)
        {
            ulaz = newElement;
        }
        else
        {
            izlaz->next = newElement;
        }
        izlaz = newElement;
        return true;
    }

    bool poljeURed(int polje[], int n)
    {
        if (n == 0)
        {
            return true;
        }
        if (dodaj(polje[0]))
        {
            return poljeURed(++polje, --n);
        }
        return false;
    }

    bool skini(int &broj)
    {
        if (ulaz == nullptr)
            return false;
        broj = ulaz->data;
        Cvor *tmp = ulaz;
        ulaz = ulaz->next;
        if (ulaz == nullptr)
            izlaz = nullptr;
        delete tmp;
        return true;
    }
};

int main(void)
{
    srand(time(NULL));

    Red q;
    int polje[10];

    for (int i = 0; i < 10; i++)
    {
        polje[i] = rand() % 10 + 1;
        cout << polje[i] << ' ';
    }
    cout << endl;

    q.poljeURed(polje, 10);

    int item;
    while (q.skini(item))
        cout << item << " ";
    cout << endl;

    return 0;
}
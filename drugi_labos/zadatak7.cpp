#include <iostream>

using namespace std;

struct Cvor
{
    double data;
    Cvor *next;
};

class Red
{
private:
    Cvor *read = nullptr;
    Cvor *write = nullptr;

public:
    bool dodaj(double broj)
    {
        Cvor *newElement = new (nothrow) Cvor;
        if (newElement == nullptr)
            return false;
        newElement->next = nullptr;
        newElement->data = broj;
        if (write == nullptr)
        {
            read = newElement;
        }
        else
        {
            write->next = newElement;
        }
        write = newElement;
        return true;
    }

    bool skini(double &broj)
    {
        if (read == nullptr)
            return false;
        broj = read->data;
        Cvor *tmp = read;
        read = read->next;
        if (read == nullptr)
            write = nullptr;
        delete tmp;
        return true;
    }
};
int main(void)
{
    Red q;

    int n;
    cout << "Upisite n: ";
    cin >> n;

    double item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        q.dodaj(item);
    }

    while (q.skini(item))
        cout << item << " ";
    cout << endl;

    return 0;
}
#include <iostream>

using namespace std;

class Queue
{
private:
    const static int MAX = 10;
    double queue[MAX];
    int ulaz = 0;
    int izlaz = 0;

public:
    bool dodaj(double item)
    {
        if ((ulaz + 1) % MAX == izlaz)
            return false;
        queue[ulaz] = item;
        ulaz = (ulaz + 1) % MAX;
        return true;
    }
    bool skini(double &item)
    {
        if (ulaz == izlaz)
            return false;
        item = queue[izlaz];
        izlaz = (izlaz + 1) % MAX;
        return true;
    }
};
int main(void)
{
    Queue *q = new Queue();

    int n;
    cout << "Upisite n: ";
    cin >> n;

    double item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        q->dodaj(item);
    }

    while (q->skini(item))
        cout << item << ' ';
    cout << endl;

    return 0;
}
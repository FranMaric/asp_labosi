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
    bool enqueue(double item)
    {
        if ((ulaz + 1) % MAX == izlaz)
            return false;
        queue[ulaz] = item;
        ulaz = (ulaz + 1) % MAX;
        return true;
    }
    bool dequeue(double &item)
    {
        if (ulaz == izlaz)
            return false;
        item = queue[izlaz];
        izlaz = (izlaz + 1) % MAX;
        return true;
    }
    int count()
    {
        if (ulaz >= izlaz)
        {
            return (ulaz - izlaz);
        }
        else
        {
            return (ulaz - izlaz + MAX);
        }
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
        q->enqueue(item);
    }

    while (q->dequeue(item))
        cout << item << ' ';
    cout << endl;

    return 0;
}
#include <iostream>
#include <time.h>

using namespace std;

class Stack
{
private:
    static const int MAX = 100;
    int stack[MAX];
    int top;

public:
    Stack() : top(-1) {}

    bool push(int item)
    {
        if (top >= MAX)
            return false;
        stack[++top] = item;
        return true;
    }
    bool pop(int &item)
    {
        if (top < 0)
            return false;
        item = stack[top--];
        return true;
    }
    void print()
    {
        for (int i = 0; i < top + 1; i++)
        {
            cout << stack[i] << ' ';
        }
        cout << endl;
    }
};

int main()
{
    srand(time(NULL));
    Stack *stog = new Stack();

    for (int i = 0; i < 101; i++)
    {
        stog->push(rand() % 100 + 1);
    }

    stog->print();

    return 0;
}
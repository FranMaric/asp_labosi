#include <iostream>
#include <time.h>

using namespace std;

struct StackElement
{
    int data;
    StackElement *next;
};

class Stack
{
private:
    StackElement *top;

public:
    Stack()
    {
        top = nullptr;
    }

    bool push(int item)
    {
        StackElement *newElement = new (nothrow) StackElement();
        if (newElement == nullptr)
            return false;

        newElement->data = item;
        newElement->next = top;
        top = newElement;

        return true;
    }

    bool pop(int &item)
    {
        if (top == nullptr)
            return false;
        item = top->data;
        StackElement *tmp = top;
        top = top->next;
        delete tmp;
        return true;
    }

    void print()
    {
        for (StackElement *p = top; p; p = p->next)
        {
            cout << p->data << ' ';
        }

        cout << endl;
    }
};

int main(void)
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
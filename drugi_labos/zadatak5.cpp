#include <iostream>
#include <time.h>

using namespace std;

class Stack
{
private:
    static const int MAX = 10;
    int stack[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

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
};

int main()
{
    srand(time(NULL));
    Stack *stog = new Stack(), *pom = new Stack();

    for (int i = 0; i < 10; i++)
    {
        stog->push(rand() % 10 + 1);
    }

    int temp;
    for (int i = 0; i < 10; i++)
    {
        stog->pop(temp);
        pom->push(temp);
    }

    for (int i = 0; i < 10; i++)
    {
        pom->pop(temp);
        cout << temp << ' ';
    }

    cout << endl;

    return 0;
}
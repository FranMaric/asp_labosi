#include <iostream>
#include <string>

using namespace std;

class ListElement
{
public:
    string data;
    ListElement *previous;
    ListElement *next;
};

class List
{
private:
    ListElement *head;

public:
    List()
    {
        head = nullptr;
    }

    bool upis(string element)
    {
        ListElement *novi = new ListElement();
        novi->data = element;
        novi->next = nullptr;

        if (head == nullptr)
        {
            novi->previous = nullptr;
            head = novi;
            return true;
        }

        ListElement *p = head;

        while (p->next != nullptr)
        {
            p = p->next;
        }

        novi->previous = p;
        p->next = novi;

        return true;
    }

    void ispis()
    {
        ListElement *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Upisite n: ";
    cin >> n;

    List *lista = new List();
    string temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        lista->upis(temp);
    }

    lista->ispis();

    return 0;
}
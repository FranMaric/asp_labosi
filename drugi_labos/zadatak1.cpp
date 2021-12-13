#include <iostream>

using namespace std;

template <typename T>
class ListElement
{
public:
    T data;
    ListElement<T> *next;
};

template <typename T>
class List
{
private:
    ListElement<T> *head;

public:
    List()
    {
        head = nullptr;
    }

    bool upis(T element)
    {
        ListElement<T> *novi = new ListElement<T>;

        novi->data = element;
        novi->next = nullptr;

        if (head == nullptr)
        {
            head = novi;
            return true;
        }

        ListElement<T> *pomocni = head;

        if (pomocni->data > element)
        {
            novi->next = pomocni;
            head = novi;
            return true;
        }

        while (pomocni->next != nullptr)
        {
            if (pomocni->next->data > element)
            {
                novi->next = pomocni->next;
                pomocni->next = novi;
                return true;
            }
            pomocni = pomocni->next;
        }

        pomocni->next = novi;

        return true;
    }

    void ispis()
    {
        ListElement<T> *temp = head;

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

    List<int> *lista = new List<int>();
    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        lista->upis(temp);
    }

    lista->ispis();

    return 0;
}
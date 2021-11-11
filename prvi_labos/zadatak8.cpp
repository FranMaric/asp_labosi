#include <iostream>
#include <string>

using namespace std;

class SanitizedString
{
public:
    SanitizedString(string str) : str(str) {}
    string str;

    void removeDuplicateWhitespace()
    {
        int j;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                j = i;
                while (str[j] == ' ')
                {
                    j++;
                }
                if (j - i > 1)
                {
                    str.erase(i + 1, j - i - 1);
                    i = j;
                }
            }
        }
    }

    void removeNonAlphaChars()
    {
        for (int i = str.size() - 1; i >= 0; i--)
        {
            if (str[i] != 32 && 65 > str[i] || str[i] > 90 && 97 > str[i] || str[i] > 122)
            {
                str.erase(i, 1);
            }
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const SanitizedString &str);
};

std::ostream &operator<<(std::ostream &os, const SanitizedString &str)
{
    os << str.str;
    return os;
}

int main()
{
    string str;
    cout << "Unesite niz: ";
    getline(cin, str);

    SanitizedString sanString = SanitizedString(str);

    cout << "Ulaz : ";
    cout << sanString << endl;

    sanString.removeNonAlphaChars();
    sanString.removeDuplicateWhitespace();

    cout << "Izlaz: ";
    cout << sanString << endl;

    return 0;
}
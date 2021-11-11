#include <iostream>
#include <string>

using namespace std;

char *ostaviSlova(string ulaz)
{
    char *izlaz = (char *)malloc(ulaz.size());

    int j = 0;
    for (int i = 0; ulaz[i] != '\0'; i++)
    {
        if (65 <= ulaz[i] && ulaz[i] <= 90 || 97 <= ulaz[i] && ulaz[i] <= 122)
        {
            izlaz[j] = ulaz[i];
            j++;
        }
    }
    izlaz[j] = '\0';
    return izlaz;
}

int main()
{
    string ulaz = "asp12_i_ASP13";

    cout << ostaviSlova(ulaz);

    return 0;
}

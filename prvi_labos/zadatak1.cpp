#include <iostream>

using namespace std;

void ispis(float polje[], int n)
{
    if (n > 0)
    {
        if (*polje < 0)
        {
            cout << *polje;
        }
        ispis(++polje, --n);
    }
}

int main()
{
    int n;
    cout << "Koliko brojeva zelite unijeti?";
    cin >> n;

    float *nums = (float *)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++)
    {
        cin >> *nums;
        nums++;
    }

    nums -= n;

    ispis(nums, n);

    return 0;
}

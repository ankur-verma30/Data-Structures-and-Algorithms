#include <iostream>
using namespace std;
int main()
{
    int i;
    char c[] = "WElCome";
    for (i = 0; c[i] != '\0'; i++)
    {
        if (c[i] >= 65 && c[i] <= 90)
            c[i] += 32;
        else if (c[i] >= 'a' && c[i] <= 122)
            c[i] -= 32;
    }
    cout << " Toggled string is = " << c;
    return 0;
}
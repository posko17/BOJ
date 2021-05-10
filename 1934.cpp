#include <iostream>

using namespace std;

int main()
{
    int min, max;
    int a, b;
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cin >> a >> b;
        for (int i = 1; i <= (a < b ? a : b); i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                min = i;
            }
        }
        max = a / min * b;
        cout << max << '\n';
    }
    return 0;
}
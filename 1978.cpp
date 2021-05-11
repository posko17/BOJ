#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        bool check = true;
        cin >> a;
        if (a == 1)
        {
            continue;
        }
        for (int j = 2; j < a; j++)
        {
            if (a % j == 0)
            {
                check = false;
                continue;
            }
        }
        if (check)
        {
            count++;
        }
    }
    cout << count;
}
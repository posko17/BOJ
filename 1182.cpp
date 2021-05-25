#include <iostream>

using namespace std;

int count = 0;

int n, s;
int arr[20];

void add(int, int);

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    add(0, 0);
    if (s == 0 && count > 0)
        count--;
    cout << count;
}

void add(int index, int cur)
{
    if (index == n)
    {
        if (cur == s)
            count++;
        return;
    }
    //add
    add(index + 1, cur + arr[index]);
    //dont add
    add(index + 1, cur);
    return;
}
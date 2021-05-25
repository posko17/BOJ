#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

const int MAX = 50;

bool is_visited[MAX];
int digit[MAX];

int n;

void find(int count, int start)
{
    if (count == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (!is_visited[i])
                continue;
            cout << digit[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = start; i < n; i++)
    {
        if (is_visited[i])
            continue;
        else
        {
            is_visited[i] = true;
            find(count - 1, i + 1);
            is_visited[i] = false;
        }
    }
    return;
}
int main()
{
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> digit[i];
        }
        find(6, 0);
        cout << '\n';
    }
    return 0;
}
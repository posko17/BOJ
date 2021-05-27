#include <iostream>

using namespace std;
int n, m;
bool is_visited[9];
void find(int cur, int count)
{
    if (count > m)
    {
        for (int i = 1; i <= n; i++)
        {
            if (is_visited[i])
                cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    else if (cur > n)
    {
        return;
    }
    for (int i = cur; i <= n; i++)
    {
        if (!is_visited[i])
        {
            is_visited[i] = true;
            find(i + 1, count + 1);
            is_visited[i] = false;
        }
    }
    return;
}
int main()
{
    cin >> n >> m;
    find(1, 1);
    return 0;
}
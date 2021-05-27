#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool is_visited[9];
void find(int);
vector<int> v;

int main()
{
    cin >> n >> m;
    find(1);
}

void find(int count)
{
    if (count > m && v.size() == m)
    {
        for (int i = 0; i < m; i++)
            cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    if (count > m)
    {
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!is_visited[i])
        {
            v.push_back(i);
            is_visited[i] = true;
            find(count + 1);
            v.pop_back();
            is_visited[i] = false;
        }
    }
    return;
}
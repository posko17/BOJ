#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int arr[9];
vector<int> v;
int n, m;
bool is_visited[9];
void find(int index, int count);

int main()
{
    cin >> n >> m;
    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        q.push(a);
    }
    arr[0] = -1;
    int i = 1;
    while (q.size())
    {
        arr[i++] = q.top();
        q.pop();
    }
    find(1, 1);
    return 0;
}
void find(int index, int count)
{
    if (count > m)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!is_visited[i])
        {
            if (arr[i] == arr[i - 1] && !is_visited[i - 1])
                continue;
            is_visited[i] = true;
            v.push_back(arr[i]);
            find(index + 1, count + 1);
            v.pop_back();
            is_visited[i] = false;
        }
    }
    return;
}
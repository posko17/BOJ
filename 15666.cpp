
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
int arr_size = 0;
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
        if (arr[i - 1] == q.top())
        {
            q.pop();
            continue;
        }
        arr[i++] = q.top();
        arr_size++;
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
    for (int i = 1; i <= arr_size; i++)
    {
        if (v.size() == 0)
        {
            v.push_back(arr[i]);
            find(index + 1, count + 1);
            v.pop_back();
        }
        else if (v.back() <= arr[i])
        {
            v.push_back(arr[i]);
            find(index + 1, count + 1);
            v.pop_back();
        }
    }
    return;
}
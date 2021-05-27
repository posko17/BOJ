#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, m;
void find(int count)
{
    if (count > m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
        find(count + 1);
        v.pop_back();
    }
    return;
}
int main()
{
    cin >> n >> m;
    find(1);
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int MAX = 10001;

int location[MAX];
bool is_visited[MAX];
priority_queue<int> g;
priority_queue<int, vector<int>, greater<int> > l;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> location[i];
        is_visited[location[i]] = true;
    }

    l.push(location[n]);
    g.push(location[n]);
    is_visited[location[n]] = false;

    for (int i = n - 1; i > 0; i--)
    {
        l.push(location[i]);
        g.push(location[i]);
        is_visited[location[i]] = false;
        if (location[i] > l.top())
        {
            int d = location[i];
            while (1)
            {
                d--;
                if (is_visited[d] == false)
                {
                    location[i] = d;
                    is_visited[d] = true;
                    break;
                }
            }
            for (int j = i + 1; j <= n; j++)
            {
                while (is_visited[g.top()])
                {
                    g.pop();
                }

                location[j] = g.top();
                is_visited[g.top()] = true;
                g.pop();
            }
            break;
        }
    }
    while (is_visited[g.top()] && g.size())
    {
        g.pop();
    }
    if (g.size() == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << location[i] << ' ';
        }
    }
    else
        cout << -1;

    return 0;
}
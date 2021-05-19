#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool is_visited[9];
int digit[9];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        digit[i] = i;
        is_visited[i] = true;
    }
    bool is_max;
    int count = 0;
    while (1)
    {
        is_max = true;
        for (int i = 0; i < n; i++)
            if (digit[n - i] != i + 1)
                is_max = false;
        count++;
        for (int i = 1; i <= n; i++)
            cout << digit[i] << ' ';
        cout << '\n';

        //move to next permutation
        if (is_max)
            break;
        priority_queue<int> g;
        priority_queue<int, vector<int>, greater<int>> l;
        for (int i = n; i > 0; i--)
        {
            g.push(digit[i]);
            l.push(digit[i]);
            is_visited[digit[i]] = false;
            if (digit[i] < g.top())
            {
                int d = digit[i];
                while (1)
                {
                    d++;
                    if (is_visited[d] == false)
                    {
                        digit[i] = d;
                        is_visited[d] = true;
                        break;
                    }
                }
                for (int j = i + 1; j <= n; j++)
                {
                    while (is_visited[l.top()])
                    {
                        l.pop();
                    }
                    digit[j] = l.top();
                    is_visited[l.top()] = true;
                    l.pop();
                }
                break;
            }
        }
    }
    //cout << count;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool is_visited[9];
int digit[9];
int arr[9];
int main()
{
    int n;
    cin >> n;
    for (int i = 1, a; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        digit[i] = i;
        is_visited[i] = true;
    }
    bool is_max;
    int count = 0;
    priority_queue<int> q;
    while (1)
    {
        is_max = true;
        for (int i = 0; i < n; i++)
            if (digit[n - i] != i + 1)
                is_max = false;
        count++;
        int m = 0;
        for (int i = 1; i < n; i++)
        {
            int temp = arr[digit[i]] - arr[digit[i + 1]];
            if (temp < 0)
                m -= temp;
            else
                m += temp;
        }
        q.push(m);

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
    cout << q.top();
    //cout << count;
    return 0;
}
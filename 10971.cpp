#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
const int MAX = 11;
bool is_visited[MAX];
int digit[MAX];
int expense[MAX][MAX];
int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        digit[i] = i;
        is_visited[i] = true;
    }
    for (int i = 1, a; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            expense[i][j] = a;
        }
    }
    bool is_max;
    int count = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    while (1)
    {
        is_max = true;
        for (int i = 0; i < n; i++)
        {
            if (digit[n - i] != i + 1)
                is_max = false;
        }
        count++;
        //cal expense
        int exp_max = 0;

        for (int i = 1; i < n; i++)
        {
            if (expense[digit[i]][digit[i + 1]] == 0)
            {
                exp_max = -1;
                break;
            }
            else
            {
                exp_max += expense[digit[i]][digit[i + 1]];
            }
        }
        if (expense[digit[n]][digit[1]] == 0)
            exp_max = -1;
        else if (expense[digit[n]][digit[1]] != 0 && exp_max != -1)
            exp_max += expense[digit[n]][digit[1]];
        /*
        cout << exp_max << '\n';
        for (int i = 1; i <= n; i++)
        {
            cout << digit[i] << ' ';
        }
        cout << '\n';
    */
        q.push(exp_max);
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
    while (q.top() == -1)
    {
        q.pop();
    }
    cout << q.top();
    //cout << count;
    return 0;
}
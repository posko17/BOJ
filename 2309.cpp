#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> q;
    int a, sum = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> a;
        sum += a;
        v.push_back(a);
    }
    sum -= 100;
    bool check = false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (v[i] + v[j] == sum)
            {
                v[i] = 0;
                v[j] = 0;
                check = true;
                break;
            }
        }
        if (check)
            break;
    }
    for (int i = 0; i < 9; i++)
    {
        q.push(v[i]);
    }
    while (q.size())
    {
        if (q.top() == 0)
            q.pop();
        else
        {
            cout << q.top() << '\n';
            q.pop();
        }
    }
    return 0;
}
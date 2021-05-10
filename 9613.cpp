#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
priority_queue<int> q;
void gcd(int, int);
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int min, max;
    int a, b;
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n, temp;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                gcd((v[i] < v[j] ? v[j] : v[i]), (v[i] > v[j] ? v[j] : v[i]));
            }
        }
        int sum = 0;
        while (q.size())
        {
            sum += q.top();
            q.pop();
        }
        cout << sum << '\n';
    }
    return 0;
}
void gcd(int greater, int less)
{
    int r;
    r = greater % less;
    if (r == 0)
    {
        q.push(less);
        return;
    }
    else
    {
        gcd(less, r);
    }
    return;
}
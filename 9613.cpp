#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
typedef long long ll;
priority_queue<ll> q;
void gcd(ll, ll);

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    ll min, max;
    ll a, b;
    ll t;
    cin >> t;
    for (ll j = 0; j < t; j++)
    {
        ll n, temp;
        cin >> n;
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        for (ll i = 0; i < v.size(); i++)
        {
            for (ll j = i + 1; j < v.size(); j++)
            {
                gcd((v[i] < v[j] ? v[j] : v[i]), (v[i] > v[j] ? v[j] : v[i]));
            }
        }
        ll sum = 0;
        while (q.size())
        {
            sum += q.top();
            q.pop();
        }
        cout << sum << '\n';
    }
    return 0;
}
void gcd(ll greater, ll less)
{
    ll r;
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
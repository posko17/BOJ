#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int MAX = 16;
int n;
int max_profit;
int t[MAX], p[MAX];

int mprofit(int);

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> p[i];
    }
    cout << mprofit(1);
}

int mprofit(int day)
{
    if (day > n)
        return 0;
    //can do today?
    if (day + t[day] - 1 > n)
    {
        //cant do
        return mprofit(day + 1);
    }
    else
    {
        //can do
        return max(mprofit(day + 1), p[day] + mprofit(day + t[day]));
    }
}
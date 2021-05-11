#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> v;
int prime[1000001] = {0};
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    v.push_back(2);
    for (int i = 3; i < 1000000; i += 2)
    {
        bool check = true;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j] * v[j] > i)
                break;
            if (i % v[j] == 0)
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            v.push_back(i);
            prime[i] = 1;
        }
    }

    while (1)
    {
        cin >> a;
        bool check = false;
        if (a == 0)
        {
            break;
        }
        int i, j;
        int indexa, indexb;
        for (i = 0; i < v.size(); i++)
        {
            if (prime[a - v[i]] == 1)
            {
                indexa = v[i];
                indexb = a - v[i];
                check = true;
                break;
            }
            if (check)
                break;
        }
        if (check)
        {
            cout << a << " = " << indexa << " + " << indexb << '\n';
        }
        else
        {
            cout << "\"Goldbach's conjecture is wrong.\"" << '\n';
        }
    }
}
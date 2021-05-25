#include <iostream>
#include <string>
#include <fstream>

using namespace std;
bool arr[21];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        int temp;
        cin >> str;
        if (str.compare("add") == 0)
        {
            cin >> temp;
            arr[temp] = true;
        }
        if (str.compare("remove") == 0)
        {
            cin >> temp;
            arr[temp] = false;
        }
        if (str.compare("check") == 0)
        {
            cin >> temp;
            if (arr[temp])
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        if (str.compare("toggle") == 0)
        {
            cin >> temp;
            arr[temp] = !arr[temp];
        }
        if (str.compare("all") == 0)
        {
            for (int i = 1; i <= 26; i++)
            {
                arr[i] = true;
            }
        }
        if (str.compare("empty") == 0)
        {
            for (int i = 1; i <= 26; i++)
            {
                arr[i] = false;
            }
        }
    }
}
/*
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        int temp;
        cin >> str;
        if (str.compare("add") == 0)
        {
            cin >> temp;
            temp--;
            b = b | (1 << temp);
        }
        if (str.compare("remove") == 0)
        {
            cin >> temp;
            temp--;
            b = b | (1 << temp);
            b = b ^ (1 << temp);
        }
        if (str.compare("check") == 0)
        {
            cin >> temp;
            temp--;
            if (b & (1 << temp))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        if (str.compare("toggle") == 0)
        {
            cin >> temp;
            temp--;
            b = b ^ (1 << temp);
        }
        if (str.compare("all") == 0)
        {
            b = (1 << 20) - 1;
            continue;
        }
        if (str.compare("empty") == 0)
        {
            b = 0;
        }
    }
}
*/
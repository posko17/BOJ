/*
    think of a state machine
    subject: digital system

    out of state? ->NO
    string in ends in the end state?->YES

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    char c;
    cin >> n;
    int status = 0;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        status = 0;
        bool check = true;
        string::iterator it = s.begin();
        while (it != s.end())
        {
            switch (status)
            {
            case 0:
                if (*it == 48)
                {
                    status = 1;
                }
                else
                {
                    status = 2;
                }
                break;
            case 1:
                if (*it == 48)
                {
                    check = false;
                    break;
                }
                else
                {
                    status = 3;
                }
                break;
            case 2:
                if (*it == 48)
                {
                    status = 4;
                }
                else
                {
                    check = false;
                    break;
                }
                break;
            case 3:
                if (*it == 48)
                {
                    status = 1;
                }
                else
                {
                    status = 2;
                }
                break;
            case 4:
                if (*it == 48)
                {
                    status = 5;
                }
                else
                {
                    check = false;
                    break;
                }
                break;
            case 5:
                if (*it == 48)
                {
                    status = 5;
                }
                else
                {
                    status = 6;
                }
                break;
            case 6:
                if (*it == 48)
                {
                    status = 1;
                }
                else
                {
                    status = 7;
                }
                break;
            case 7:
                if (*it == 48)
                {
                    status = 8;
                }
                else
                {
                    status = 7;
                }
                break;
            case 8:
                if (*it == 48)
                {
                    status = 5;
                }
                else
                {
                    status = 0;
                }
                break;
            default:
                break;
            }
            if (!check)
            {
                break;
            }
            it++;
        }
        if (status == 0 || status == 3 || status == 6 || status == 7 && check)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
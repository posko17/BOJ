#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int n;
    cin >> n;
    list<char> a;
    list<char> space;
    space.push_back('\n');
    list<list<char>> l;
    a.push_back('*');
    l.push_back(a);
    for (int i = 1; i < n; i++)
    {
        list<char> temp1, temp2;
        for (int j = 0; j < l.front().size() + 4; j++)
        {
            temp1.push_back('*');
        }
        for (int j = 0; j < l.front().size() + 2; j++)
        {
            temp2.push_back(' ');
        }
        temp2.push_back('*');
        temp2.push_front('*');
        for (list<list<char>>::iterator it = l.begin(); it != l.end(); it++)
        {
            (*it).push_front(' ');
            (*it).push_front('*');
            (*it).push_back(' ');
            (*it).push_back('*');
        }
        l.push_front(temp2);
        l.push_front(temp1);
        l.push_back(temp2);
        l.push_back(temp1);
    }
    int size = l.size();
    for (int i = 0; i < size; i++)
    {
        while (l.front().size() > 0)
        {
            cout << l.front().front();
            l.front().pop_front();
        }

        l.pop_front();
        if (i != l.size() - 1)
            cout << '\n';
    }
}
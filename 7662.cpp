#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
class number
{
public:
    number(int a)
    {
        is_available = true;
        n = a;
    }
    bool is_available;
    int n;
};
class mycomparison
{
    bool reverse;

public:
    mycomparison(const bool &revparam = false)
    {
        reverse = revparam;
    }
    bool operator()(const number *lhs, const number *rhs) const
    {
        if (reverse)
            return (lhs->n > rhs->n);
        else
            return (lhs->n < rhs->n);
    }
};
int main()
{
    int n;
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int op;
        int count = 0;
        char cc;
        int ic;
        priority_queue<number *, vector<number *>, mycomparison> maxq(mycomparison(false));
        priority_queue<number *, vector<number *>, mycomparison> minq(mycomparison(true));
        vector<number *> v;
        cin >> op;
        for (int j = 0; j < op; j++)
        {
            cin >> cc >> ic;
            number *temp = new number(ic);
            v.push_back(temp);
            if (cc == 'I')
            {
                count++;
                maxq.push(temp);
                minq.push(temp);
            }
            else if (cc == 'D')
            {
                count--;
                if (count <= 0)
                {
                    while (!maxq.empty())
                    {
                        maxq.top()->is_available = false;
                        maxq.pop();
                    }
                    while (!minq.empty())
                    {
                        minq.top()->is_available = false;
                        minq.pop();
                    }
                    count = 0;
                    continue;
                }
                if (ic == 1)
                {
                    while (!maxq.top()->is_available && !maxq.empty()) //pop false
                    {
                        maxq.pop();
                    }
                    maxq.top()->is_available = false;
                    maxq.pop();
                }
                else if (ic == -1)
                {
                    while (!minq.top()->is_available && !minq.empty())
                    {
                        minq.pop();
                    }
                    minq.top()->is_available = false;
                    minq.pop();
                }
                else
                {
                    cout << "error!\n ";
                }
            }
            else
            {
                cout << "error!\n ";
            }
        }

        while (!maxq.top()->is_available && !maxq.empty())
        {
            maxq.pop();
        }

        while (!minq.top()->is_available && !minq.empty())
        {
            minq.pop();
        }

        if (maxq.empty())
        {
            cout << "EMPTY\n";
            while (!maxq.empty())
            {
                maxq.pop();
            }
            while (!minq.empty())
            {
                minq.pop();
            }
        }
        else
        {
            cout << maxq.top()->n << ' ' << minq.top()->n << '\n';
            while (!maxq.empty())
            {
                maxq.pop();
            }
            while (!minq.empty())
            {
                minq.pop();
            }
        }
        for (vector<number *>::iterator it = v.begin(); it != v.end(); it++)
        {
            delete *it;
        }
    }
}
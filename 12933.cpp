#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int max=0;
    int current=0;
    stack<char> q;
    stack<char> u;
    stack<char> a;
    stack<char> c;
    stack<char> k;
    char h;
    while((h=getchar())!='\n')
    {
        switch(h)
        {
            case 'q':
                current++;
                if(current>max)
                    max=current;
                q.push('q');
                break;
            case 'u':
                if(q.size()>0)
                {
                    q.pop();
                    u.push('u');
                }
                else{
                    cout<<-1;
                    return 0;
                }
                break;
            case 'a':
                if(u.size()>0)
                {
                    u.pop();
                    a.push('a');
                }
                else{
                    cout<<-1;
                    return 0;
                }
                break;
            case 'c':
                if(a.size()>0)
                {
                    a.pop();
                    c.push('c');
                }
                else{
                    cout<<-1;
                    return 0;
                }
                break;
            case 'k':
                if(c.size()>0)
                {
                    c.pop();
                    current--;
                }
                else{
                    cout<<-1;
                    return 0;
                }
                break;
            default:
                cout<<-1;
                return 0;
                break;
        }
    }
    if(q.size()>0||u.size()>0||a.size()>0||c.size()>0||k.size()>0)
    {
        cout<<-1;
        return 0;
    }
    cout<<max;
}
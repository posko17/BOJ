#include <iostream>
#include <list>
using namespace std;
int main()
{
    int n,k;
    list<int> l;
    cin>>n>>k;
    for(int i=0;i<=n;i++)
    {
        l.push_back(i);
    }
    int t=0;
    int total_size=0;
    list<int>::iterator it;
    while(l.size()>1)
    {
        t+=k;
        it=l.begin();
        for(int i=0;i<t%l.size();i++)
        {
            it++;
        }
        if(l.size()==2)
        {
            cout<<*it;
            break;
        }
        else
        {
            cout<<*it<<", ";
            l.erase(it);
        }
    }
}
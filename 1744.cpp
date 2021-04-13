#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int n,t;
    cin>>n;
    priority_queue<int> q;
    vector<int> pos;
    vector<int> neg;
    vector<int> zer;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        q.push(t);
    }
    for(int i=0;i<n;i++)
    {
        if(q.top()>0)
            pos.push_back(q.top());
        else if(q.top()<=0)
            neg.push_back(q.top());
        q.pop();
    }
    int sum=0;
    int i=0;
    while(i<pos.size())
    {
        if(pos.size()-i>=2)
        {
            if(pos[i]*pos[i+1]>pos[i]+pos[i+1])
            {
                sum+=pos[i]*pos[i+1];
                i++;
                i++;
            }
            else
            {
                sum+=pos[i];
                i++;
            }
        }
        else
        {
            sum+=pos[i];
            i++;
        }
    }
    while(neg.size())
    {
        if(neg.size()>=2)
        {
             if(neg[neg.size()-1]*neg[neg.size()-2]>neg[neg.size()-1]+neg[neg.size()-2])
             {
                 sum+=neg[neg.size()-1]*neg[neg.size()-2];
                 neg.pop_back();
                 neg.pop_back();
             }
             else
             {
                sum+=neg[neg.size()-1];
                neg.pop_back();
             }
        }
        else
        {
            sum+=neg[neg.size()-1];
            neg.pop_back();
        }
    }
    cout<<sum;
}
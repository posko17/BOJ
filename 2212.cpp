#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int t;
    if(k>n)
        k=n;
    priority_queue<int> q,s;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        q.push(t);
    }
    int a=q.top();
    int b;
    while(q.size()>1)
    {
        q.pop();
        b=q.top();
        s.push(a-b);
        a=b;
    }
    for(int i=0;i<k-1;i++)
    {
        s.pop();
    }
    int sum=0;
    while(s.size())
    {
        sum+=s.top();
        s.pop();
    }
    cout<<sum;
}
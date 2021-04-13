#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class time_
{
    public:
    int start;
    int end;
    void operator() ( int a, int b)
    {
        start=a;
        end=b;
    }
};
class mycomparison
{
    public:
    bool operator() (const time_& a, const time_& b)
    {
        if(a.end==b.end)
        {
            return a.start>b.start;
        }
        else
        {
            return a.end>b.end;
        }
    }
};

int main()
{
    int n;
    cin>>n;
    time_ t;
    priority_queue<time_,vector<time_>,mycomparison> q;
    for(int i=0,a,b;i<n;i++)
    {
        cin>>a>>b;
        t(a,b);
        q.push(t);
    }
    int pst=0,pet=0,cst,cet;
    int count=0;
    while(q.size()>0)
    {
        cst=q.top().start;
        cet=q.top().end;
        if(cst>=pet)
        {
            count++;
            pst=cst;
            pet=cet;
            q.pop();
        }
        else
        {
            q.pop();
        }
    }
    cout<<count;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class time_
{
    public:
    int time;
    bool is_start;
    void operator() (int a, bool b)
    {
        time=a;
        is_start=b;
    }
};
class mycomparison
{
    public:
    bool operator() (const time_& a, const time_& b)
    {
        if(a.time==b.time)
        {
            if(a.is_start||!b.is_start)//endtime first;
            {
                return true;
            }
            else if(!a.is_start||b.is_start)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return a.time>b.time;
        }
    }
};
int main()
{
    int n;
    cin>>n;
    time_ t1,t2;

    priority_queue<time_,vector<time_>,mycomparison> q;
    for(int i=0,a,b;i<n;i++)
    {
        cin>>a>>b;
        t1(a,true);
        t2(b,false);
        q.push(t1);
        q.push(t2);
    }
    int count=0,max=0;;
    while(!q.empty())
    {
        if(q.top().is_start)
        {
            count++;
            if(count>max)
            {
                max= count;
            }
        }
        else
        {
            count--;
            if(count<0)
            {
                cout<<"fucking error";
            }
        }
        q.pop();
    }
    cout<<max;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class assign
{
    public:
    int dead;
    int score;
    void operator() ( int a, int b)
    {
        dead=a;
        score=b;
    }
};
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const assign& lhs, const assign& rhs) const
  {
    if(lhs.dead==rhs.dead)
    {
        return lhs.score<rhs.score;
    }
    else 
    {
        return lhs.dead<rhs.dead;
    }
  }
};
class mycomparison_
{
  bool reverse;
public:
  mycomparison_(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const assign& lhs, const assign& rhs) const
  {
    if(lhs.score==rhs.score)
    {
        return lhs.dead<rhs.dead;
    }
    else 
    {
        return lhs.score<rhs.score;
    }
  }
};
int main()
{
    int a,b,n;
    cin>>n;
    assign ds[1000];
    priority_queue<assign,vector<assign>,mycomparison> q;//deadline;
    priority_queue<assign,vector<assign>,mycomparison_> ans;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        ds[i](a,b);
        q.push(ds[i]);
    }
    int current_Day=q.top().dead;
    int sum=0;
    while(current_Day>0)
    {
        /*
        cout<<"dead: "<<q.top().dead<<'\n';
        cout<<"score: "<<q.top().score<<'\n';
        q.pop();
        */
        while(current_Day<=q.top().dead&&!q.empty())
        {
            ans.push(q.top());
            q.pop();
        }
        if(!ans.empty())
        {
            sum+=ans.top().score;
            //cout<<sum<<endl;
            ans.pop();
            current_Day--;
        }
        else
        {
            current_Day--;
            continue;
        }
        /* if(tempd==q.top().dead)
        {
            q.pop();
        }
        else
        {
            tempd=q.top().dead;
            sum+=q.top().score;
            q.pop();
        }*/
       
    }
    cout<<sum;
}
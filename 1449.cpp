#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    priority_queue<int, std::vector<int>, std::greater<int> > q;
    int n,l;
    cin>>n;
    cin>>l;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        q.push(temp);
    }
    int count=0;
    double tape_pos=-l;
    while(!q.empty())
    {
        if((tape_pos+l)<q.top()+0.5)
        {
            count++;
            tape_pos=(double)q.top()-0.5;
            q.pop();
            continue;
        }
        else
        {
            q.pop();
        }
    }
    cout<<count;
}
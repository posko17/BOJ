#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    priority_queue<int, std::vector<int>, std::greater<int> > q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        q.push(temp);
    }
    int max=0;
    int temp;
    for(int i=0;i<n;i++)
    {
        temp=q.top()*(n-i);
        if(max<temp)
        {
            max=temp;
        }
        q.pop();
    }
    cout<<max;
}
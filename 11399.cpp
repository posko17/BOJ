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
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=q.top()*(n-i);
        q.pop();
    }
    cout<<sum;
}
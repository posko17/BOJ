#include <iostream>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int count=0;
    while(1)
    {
        n-=2;
        m-=1;
        if(n>=0&&m>=0&&n+m>=k)
        {
            count++;
        }
        else
        {
            break;
        }
        
    }
    cout<<count;
}
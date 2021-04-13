#include <iostream>

using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int coin[10]={0};
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    int count=0;
    while(k!=0)
    {
        if(k/coin[n-1]==0)
        {
            n--;
        }
        count+=k/coin[n-1];
        k=k-k/coin[n-1]*coin[n-1];
    }
    cout<<count;
}
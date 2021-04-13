#include <iostream>

using namespace std;
int main()
{
    int n;
    int a[41]={0};
    cin>>n;
    for(int i=0,t;i<n;i++)
    {
        for(int j=0;j<41;j++)
        {
            a[j]=0;
        }
        cin>>t;
        int temp=t;
        if(t==1)
        {
            cout<<0<<' '<<1<<'\n';
            continue;
        }
        if(t==0)
        {
            cout<<1<<' '<<0<<'\n';
            continue;
        }

        a[t]++;
        while(t>=2)
        {
            a[t-1]+=a[t];
            a[t-2]+=a[t];  
            t--; 
        }
        cout<<a[0]<<' '<<a[1]<<'\n';
    }

}
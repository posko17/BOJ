#include <iostream>
using namespace std;
int main()
{
    int digit[10]={1,1,1,1,1,1,1,1,1,1};
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int temp[10];
        for(int j=0;j<10;j++)
            temp[j]=digit[j];
        for(int j=9;j>=0;j--)
        {
            for(int k=j-1;k>=0;k--)
            {
                digit[j]+=temp[k];
                digit[j]%=10007;
            }
        }
         for(int i=0;i<10;i++)
        {
           // cout<<"digit "<<i<<": ";
            //cout<<digit[i]<<'\n';
        }
    }
    int sum=0;
    for(int i=0;i<10;i++)
    {
        sum+=digit[i];
        sum%=10007;
    }
    cout<<sum;
}
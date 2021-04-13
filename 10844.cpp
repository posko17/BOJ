#include <iostream>
using namespace std;

int main()
{
   long long int digit[10]={0,1,1,1,1,1,1,1,1,1};
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        long long int temp[10];
        for(int k=0;k<10;k++)
            temp[k]=digit[k]%1000000000;
        for(int j=0;j<10;j++)
        {
            for(int i=0;i<10;i++)
            {
                //sum+=digit[i];
                //cout<<"digit:"<<i<<": "<<temp[i]<<'\n';
            }
            if(j==0)
                digit[j]=temp[1];
            else if(j==9)
            {
                digit[j]=temp[8];
            }
            else
            {
                digit[j]=temp[j-1]+temp[j+1];
            }
        }
    }
    long long int sum=0;
    for(int i=0;i<10;i++)
    {
        sum+=digit[i];
        //cout<<"digit:"<<i<<": "<<digit[i]<<'\n';
    }
    //cout<<sum;
    sum%=1000000000;
    cout<<sum;
}
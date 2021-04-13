#include <iostream>
using namespace std;
int main()
{
    int n;
    int wine_amount[10000]={0};
    int max0=0,max1=0,max2=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>wine_amount[i];
    }
    max0=wine_amount[0];
    max1=wine_amount[1];
    max2=wine_amount[0]+wine_amount[1];
    for(int i=2;i<n;i++)
    {
        int temp0=max0,temp1=max1,temp2=max2;
        max2=temp1+wine_amount[i];
        max1=temp0+wine_amount[i];
        if(temp0>max0)
            max0=temp0;
        if(temp1>max0)
            max0=temp1;
        if(temp2>max0)
        max0=temp2;
    }
    int temp=0;
    if(max0>temp)
        temp=max0;
    if(max1>temp)
        temp=max1;
    if(max2>temp)
        temp=max2;
    cout<<temp;
}
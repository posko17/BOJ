#include <iostream>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    int arr[2][100000]={0};
    for(int i=0;i<t;i++)
    {
        cin>>n;
        //sticker value
        for(int z=0;z<2;z++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[z][j];
            }
        }
        int max1[100000]={0};
        int max2[100000]={0};
        max1[0]=arr[0][0];
        max2[0]=arr[1][0];
        max1[1]=arr[0][1]+max2[0];
        max2[1]=arr[1][1]+max1[0];
        for(int j=2;j<n;j++)
        {
            int temp=0;
            if((arr[0][j]+max2[j-1])>temp)
            {
                temp=arr[0][j]+max2[j-1];
            }
            if((arr[0][j]+max1[j-2])>temp)
            {    
                temp=arr[0][j]+max1[j-2];
            }
            if((arr[0][j]+max2[j-2])>temp)
            {
                temp=arr[0][j]+max2[j-2];
            }
            max1[j]=temp;
            temp=0;
            if((arr[1][j]+max1[j-1])>temp)
            {
                temp=arr[1][j]+max1[j-1];
            }
            if((arr[1][j]+max2[j-2])>temp)
            {   
                temp=arr[1][j]+max2[j-2];
            }
            if((arr[1][j]+max1[j-2])>temp)
            {
                 temp=arr[1][j]+max1[j-2];
            }
            max2[j]=temp;
        }
        if(max1[n-1]>max2[n-1])
            cout<<max1[n-1]<<'\n';
        else   
            cout<<max2[n-1]<<'\n';
        for(int i=0;i<n;i++)
        {
           // cout<<max1[i]<<' '<<max2[i]<<'\n';
        }
        
    }
    return 0;
}
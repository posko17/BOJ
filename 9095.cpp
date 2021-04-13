#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        int arr[13]={0};
        arr[1]=1;
        arr[2]=2;
        arr[3]=4;
        arr[4]=7;
        if(a>4)
        {
            for(int j=5;j<=a;j++)
            {
                arr[j]=arr[j-1]+arr[j-2]+arr[j-3];
            }
        }
        cout<<arr[a]<<'\n';

    }
    
}
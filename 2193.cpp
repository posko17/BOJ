#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int arr[2]={0,1};
    for(int i=1;i<n;i++)
    {
        long long int temp[2];
        temp[0]=arr[0];
        temp[1]=arr[1];
        for(int j=0;j<2;j++)
        {
            arr[0]=temp[0]+temp[1];
            arr[1]=temp[0];
        }
    }
    cout<<arr[0]+arr[1];
}
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[1002]={0};
    arr[0]=1;
    for(int i=0;i<n;i++)
    {
        arr[i]%=10007;
        arr[i+1]+=arr[i];
        arr[i+2]+=2*arr[i];
    }
    cout<<arr[n]%10007;
    return 0;
}
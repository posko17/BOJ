#include <iostream>

using namespace std;

int main()
{
    int count=0;
    int arr[11];
    for(int i=0;i<11;i++)
    {
        arr[i]=-1;
    }
    int n;
    cin>>n;
    for(int i=0,a,b;i<n;i++)
    {
        cin>>a>>b;
        //check if it's first
        //if it's not first then check it
        if(arr[a]==-1)
        {
            arr[a]=b;
        }
        else
        {
            if(arr[a]!=b)
            {
                count++;
                arr[a]=b;
                continue;
            }
            else
            {
                continue;
            }
        }
    }
    cout<<count;
}
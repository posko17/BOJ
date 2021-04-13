#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int num;
    cin>>num;
    int arr[1001];
    vector<int> total(1001);
    total[0]=0;
    for(int i=1;i<=num;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=num;i++)
    {
        vector<int> temp(1001);
        for(int j=1;j<=i;j++)
        {
            temp[j]=arr[j]+total[i-j];
        }
        sort(temp.begin()+1,temp.begin()+i+1);
        /* cout<<"temp part:"<<i<<'\n';
        for(int j=0;j<=i;j++)
        {    
            cout<<temp[j]<<'\n';
        }*/
        total[i]=temp[i];
    }
    /* cout<<"total part:"<<'\n';
    for(int i=0;i<=num;i++)
    {
       
        cout<<total[i]<<'\n';
    }*/
    cout<<total[num];
}
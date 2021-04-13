#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n,k;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        int max,min;
        for(int j=0,a;j<k;j++)
        {
            cin>>a;
            if(j==0)
            {
                max=a;
                min=a;
            }
            else
            {
                if(max<a)
                    max=a;
                if(min>a)
                    min=a;
            }
        }
        cout<<min<<' '<<max<<'\n';
    }
}
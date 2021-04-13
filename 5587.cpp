#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool submit[31]={false};
    for(int i=1,a;i<31;i++)
    {
        cin>>a;
        submit[a]=true;
    }
    for(int i=1;i<31;i++)
    {
        if(submit[i]==false)
        {
            cout<<i<<'\n';
        }
    }
}
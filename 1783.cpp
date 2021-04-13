#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int count=1;
    int init_n=1,init_m=1;
    if(n>=3&&m>=7)
    {//restriction
        count=5;
        count=count+m-7;
    }
    else
    {// no restriction
       while(1)
       {
            if(init_n+2<=n&&init_m+1<=m)
            {
                count++;
                init_n+=2;
                init_m+=1;
                continue;
            }
            else if(init_n-2>0&&init_m+1<=m)  
            {
                count++;
                init_n-=2;
                init_m+=1;
                continue;
            }
            else if(init_n+1<=n&&init_m+2<=m)
            {
                count++;
                init_n+=1;
                init_m+=2;
                continue;
            }
            else if(init_n-1>0&&init_m+2<=m)
            {
                count++;
                init_n-=1;
                init_m+=2;
                continue;
            }
            else
            {
                break;
            }
       }
       if(count>4)
       {
           count=4;
       }
    }
    cout<<count;
}
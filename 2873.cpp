#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;
    int cur_r=1;
    int cur_c=1;
    if(r%2==1)
    {
        while(1)
        {  
            for(int i=1;i<c;i++)
            {
                cout<<'R';
            }
            if(cur_r<r)
            { 
                cout<<'D';
                cur_r++;
            }
            else
            {
                break;
            }
            for(int i=1;i<c;i++)
            {
                cout<<'L';
            }
            if(cur_r<r)
            { 
                cout<<'D';
                cur_r++;
            }
            else
            {
                break;
            }
        }
        return 0;
    }
    if(c%2==1)
    {
        while(1)
        {  
            for(int i=1;i<r;i++)
            {
                cout<<'D';
            }
            if(cur_c<c)
            { 
                cout<<'R';
                cur_c++;
            }
            else
            {
                break;
            }
            for(int i=1;i<r;i++)
            {
                cout<<'U';
            }
            if(cur_c<c)
            { 
                cout<<'R';
                cur_c++;
            }
            else
            {
                break;
            }
        }
        return 0;
    }
    //r and c even
    if(r%2==0&&c%2==0)
    {
        //abandon one row or column
    }
}
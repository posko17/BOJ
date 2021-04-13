#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int l,p,v;
    int count,i=0;
    while(1)
    { 
        cin>>l>>p>>v;
        count=0;
        if(l==0&p==0&v==0)
        {
            break;
        }
        while(1)
        { 
            
            if(v>=p)
            {
                v-=p;
                count+=l;
            }
            else
            {
                if(v>=l)
                {
                    count+=l;
                    v=0;
                    i++;
                    break;
                }
                else
                {
                    count+=v;
                    v=0;
                    i++;
                    break;
                }
            }
        }
        cout<<"Case "<<i<<": "<<count<<'\n';
    }

}
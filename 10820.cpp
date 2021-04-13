#include <iostream>

using namespace std;
int main()
{
    int count[4]={0};
    char c;
    while(1)
    {
        c=getchar();
        if(c==EOF)
            break;
        if(c>=97&&c<=122)
            count[0]++;
        else if(c>=65&&c<=90)
            count[1]++;
        else if(c>=48&&c<=57)
            count[2]++;
        else if(c==32)
            count[3]++;
        if(c=='\n')
        {
            for(int i=0;i<4;i++)
            {
                cout<<count[i]<<' ';
                count[i]=0;
            }
            cout<<'\n';
        }
    }
    
}
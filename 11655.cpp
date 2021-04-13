#include <iostream>
using namespace std;

int main()
{
    char c;
    while((c=getchar())!='\n')
    {
        if(c>=65&&c<=90)
        {
            c+=13;
            if(c>90)
            {
                c-=26;
            }
            cout<<c;
        }
        else if(c>=97&&c<=122)
        {
           if(c>=110)
           {
               c=c+13-26;
           }
           else
            c+=13;
            cout<<c;
        }
        else
        {
            cout<<c;
        }
    }
    return 0;
}
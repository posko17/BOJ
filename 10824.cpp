#include <iostream>
#include <stack>
using namespace std;

int main()
{
    char c;
    int space_count=0;
    unsigned long long int f=0,b=0;
    stack<unsigned long long int> front,back;
    while((c=getchar())!='\n')
    {
        if(c==' ')
        {
            space_count++;
            continue;
        }
        if(space_count>1)
        {
            back.push(c-48);
        }
        else
        {
            front.push(c-48);
        }
    }
    int count=0;
    while(!front.empty())
    {
      
       unsigned long long int temp=front.top();
       for(int i=0;i<count;i++)
       {
           temp*=10;
       }
        f+=temp;
        front.pop();
         count++;
    }
    count=0;
    while(!back.empty())
    {
       
       unsigned long long int temp=back.top();
       for(int i=0;i<count;i++)
       {
           temp*=10;
       }
        b+=temp;
        back.pop();
        count++;
    }
    cout<<f+b;
}
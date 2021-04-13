#include <iostream>
#include <new>
using namespace std;
int dp(int a,int count,int* min);
int main()
{
    int a;
    cin>>a;
    int count=0;
    int*min;
    try{
    min=new int;
    }
    catch(bad_alloc &b){
        puts("error!");
        b.what();
    }
    *min=1000000;
    dp(a,count,min);
    cout<<*min;
    delete min;
    return 0;
}

int dp(int a, int count,int* min)
{ 
   if(count>*min)
        return 0;
    if(a==1)
    {
        if(*min>count)
            *min=count;
        return 0;
    }
    count++;
    if(a%3==0)
        dp(a/3,count,min);
    if(a%2==0)
        dp(a/2,count,min);
    dp(a-1,count,min);
    return 0;
}
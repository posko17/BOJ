#include <iostream>

using namespace std;
int main()
{
    int count[26]={0};
    char c;
    while((c=getchar())!='\n')
    {
        count[c-97]++;
    }
    for(int i=0;i<26;i++)
    {
        cout<<count[i]<<' ';
    }
}
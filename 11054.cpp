#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int s[1002];
    for(int i=0;i<1002;i++)
    {
        s[i]=1001;
    }
    int n;
    cin>>n;
    //getting sequence value
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    //find the left and right most length
    unsigned int* no_match=new unsigned int;
    *no_match=0;
    int left_most[1002]={0};//size
    int right_most[1002]={0};//size
    for(int i=1;i<=n;i++)
    {
        //check left value length
        int left_mostIndex=-1;
        int left_mostSize=0;
        for(int j=i-1;j>-1;j--)
        {
            if(j==0)
            {//exit when the s ends
                break;
            }
            if(s[j]<s[i])
            {//found the first less value on the left
                if(left_most[j]>left_mostSize)
                {
                    left_mostIndex=j;
                    left_mostSize=left_most[j];
                }
            }
        }
        left_most[i]=left_mostSize+1;
    }
     
    for(int i=n;i>=1;i--)
    {
        //check right value length
        int right_mostIndex=-1;
        int right_mostSize=0;
        for(int j=i+1;j<=n+1;j++)
        {
            if(j==n+1)
            {//exit when the s ends
                break;
            }
            if(s[j]<s[i])
            {//found the first less value on the right
                if(right_most[j]>right_mostSize)
                {
                    right_mostIndex=j;
                    right_mostSize=right_most[j];
                }
            }
        }
        right_most[i]=right_mostSize+1;
    }
    int max_length=0;
    int max_index=-1;
    for(int i=1;i<=n;i++)
    {
        if(max_length<left_most[i]+right_most[i])
        {
            max_length=left_most[i]+right_most[i];
            max_index=i;
        }
    }
    cout<<max_length-1;
    }
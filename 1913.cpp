#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<char> q;
    int n,k;
    cin>>n>>k;
    q.push('d');
    q.push('r');
    q.push('u');
    q.push('l');
    int arr[n][n]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }
    int count=n*n;
    int i=0,j=0;
    arr[i][j]=count;
    count--;
    while(count>0)
    {
        switch(q.front())
        {
            case 'd':
                if(arr[i+1][j]!=0||i+1>=n)
                {
                    char c=q.front();
                    q.pop();
                    q.push(c);
                    continue;
                }
                else
                {
                    i++;
                }
                break;
            case 'r':
                if(arr[i][j+1]!=0||j+1>=n)
                {
                    char c=q.front();
                    q.pop();
                    q.push(c);
                    continue;
                }
                else
                {
                    j++;
                }
                break;
            case 'u':
                if(arr[i-1][j]!=0||i-1<0)
                {
                    char c=q.front();
                    q.pop();
                    q.push(c);
                    continue;
                }
                else
                {
                    i--;
                }
                break;
            case 'l':
                if(arr[i][j-1]!=0||j-1<0)
                {
                    char c=q.front();
                    q.pop();
                    q.push(c);
                    continue;
                }
                else
                {
                    j--;
                }
                break;
            default:
            break;
        }
        arr[i][j]=count;
        count--;
    }
    int cora,corb;
    for(int a=0;a<n;a++)
    {
        for(int b=0;b<n;b++)
        {
            cout<<arr[a][b]<<' ';
            if(k==arr[a][b])
            {
                cora=a+1;
                corb=b+1;
            }
        }
        cout<<'\n';
    }
    cout<<cora<<' '<<corb;
}
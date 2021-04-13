#include <iostream>
using namespace std;
void recur(int l, int w, int h, long long* count,int* cube,long long * remain);
bool solve= true;
int main()
{
    int l,w,h;
    int n;
    int a[20]={0};
    long long sum;
    long long *remain=new long long;
    *remain=0;
    cin>>l>>w>>h;
    sum=(long long)l*(long long)w*(long long)h;
    cin>>n;
    int t;
    long long* count= new long long;
    *count=0;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        cin>>a[t];
    }
    recur(l,w,h,count,a,remain);
    //cout<<(solve? *count: -1);
    if(sum==*remain)
        cout<<*count;
    else
        cout<<-1;
    /*
    for(int i=0;i<3;i++)
    {
        cout<<a[i]<<'\n';
    }
    */
}
void recur(int l, int w, int h, long long* count,int* cube,long long* remain)
{
    int max=0;
    /*
    cout<<"information of recur:"<<endl;
    cout<<" l w h *count, cube"<<endl;
    cout<<l<<" "<<w<<" "<<h<<" "<<*count<<endl;
    cout<<cube[0]<<" "<<cube[1]<<" "<<cube[2]<<endl;
    */
    if(l==0||w==0||h==0)
        return;
    
    
    int i;
    for(i=19;i>=0;i--)
    {
        if(cube[i]>0)
        {
            //check if it's fit
            if(l>=(1<<i)&&w>=(1<<i)&&h>=(1<<i))
            {
                (*count)++;
                cube[i]--;
                long long a=1;
                *remain+=(long long)(a<<i*3);
                recur(l,w,h-(1<<i),count,cube,remain);
                recur(l-(1<<i),(1<<i),(1<<i),count,cube,remain);
                recur(l,w-(1<<i),(1<<i),count,cube,remain);
                break;
            }
            else
            {
                continue;
            }
        }
    }
    if(i==-1)
        solve=false;
    return;
}
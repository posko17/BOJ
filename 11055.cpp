#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;

int main()
{
    vector<int> max[1000];
    int n;
    cin>>n;
    int temp;
    cin>>temp;
    max[0].push_back(temp);
    for(int i=1;i<n;i++)
    {
        cin>>temp;
        int size=0;
        int max_index=-1;
        int maxs=0;
         int a;
        for(int j=i-1;j>-1;j--)
        {//o(n)
        //finding max array index that fits sequence order
            if(max[j].size()!=0)
            {   
                if(max[j].back()<temp)
                {
                   
                    if((a=accumulate(max[j].begin(),max[j].end(),0))>maxs)
                    {
                        maxs=a;
                        max_index=j;
                        size=max[j].size();
                    }
                }
            }        
        }
        //pushing back the fit array
        if(size==0)
        {
            //no array that fits
            max[i].push_back(temp);
        }
        if(size!=0)//found max array
        {
            max[i]=max[max_index];
            max[i].push_back(temp);
        }   
        //O(n^2)
    }
    int max_sum=0;
    for(int i=0;i<n;i++)
    {
       int temp= accumulate(max[i].begin(),max[i].end(),0);
        if(temp>max_sum)
        {
            max_sum=temp;
        }
    }
    cout<<max_sum;
}
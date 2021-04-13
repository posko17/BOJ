#include <iostream>
#include <vector>
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
        for(int j=i-1;j>-1;j--)
        {//o(n)
        //finding max array index that fits sequence order
            if(max[j].size()!=0)
            {   
                if(max[j].back()<temp)
                {
                   if((max[j].size()) > size)
                   {
                       // cout<<"max size and current max size "<<max[j].size()<<' '<<size<<'\n'; 
                        size=max[j].size();
                        max_index=j;
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
    int max_size=0;
    for(int i=0;i<n;i++)
    {
        if(max[i].size()>max_size)
        {
            max_size=max[i].size();
        }
    }
    cout<<max_size;
}
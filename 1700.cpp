#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> multi;
    list<int> elec;
    int max=0;
    for(int i=0,t;i<k;i++)
    {
        cin>>t;
        elec.push_back(t);
    }
    /*
    1.plug until full
    2. check it's plugged
    2-1.plugged-> proceed to the next elec
    2-2. not plugged-> proceed until you find the last plugged one
    */
   int a;
    while(elec.size()>0)
    {
        int count=0;
        if(multi.size()<n)
        {
            bool is_plugged=false;
            for(int i=0;i<multi.size();i++)
            {
                if(multi[i]==elec.front())
                {
                    is_plugged=true;
                }
            }
            if(is_plugged)
            {
                elec.erase(elec.begin());
            }
            else
            {
                multi.push_back(elec.front());
                elec.erase(elec.begin());
            }
        }
        else
        {
            list<int>::iterator it=elec.begin();
            //check plugged
            bool is_plugged=false;
            for(int i=0;i<n;i++)
            {
                if(*it==multi[i])
                {
                    is_plugged=true;
                    break;
                }
            }
            if(is_plugged)
            {
                //plugged -> proceed
                elec.erase(elec.begin());
            }
            else
            {
                //not plugged->check the latest one
                bool check[n]={false};
                int max_index=-1;
                int max_value;
                it=elec.begin();
                it++;
                //checking the latest index and is full
                for(int i=0;i<n;i++)
                {
                    int c=0;
                    it=elec.begin();
                    it++;
                    for(;it!=elec.end();it++)
                    {
                        c++;
                        if(*it==multi[i])
                        {
                            check[i]=true;
                            if(max_index<c)
                            {
                                max_index=c;
                                max_value=i;
                            }
                            break;
                        }
                    }
                }
                //all meet again
                bool is_full=true;
                for(int i=0;i<n;i++)
                {
                    if(!check[i])
                    {
                        is_full=false;
                    }
                }
                if(is_full)
                {
                    multi[max_value]=*elec.begin();
                    max++;
                    elec.erase(elec.begin());
                }
                //some elecs not appeared again
                else
                {
                     for(int i=0;i<n;i++)
                    {
                        if(!check[i])
                        {
                            multi[i]=*elec.begin();
                            max++;
                            elec.erase(elec.begin());
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<max;
}
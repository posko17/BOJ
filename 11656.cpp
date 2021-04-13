#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class comp
{
    public:
    bool operator() (string i,  string j) 
    {
        if(i.compare(j)>0)
            return false;
        else
            return true;
    }
}mycomp;
int main()
{
    string str;
    cin>>str;
    vector<string> vect;
    while(!str.empty())
    {
        vect.push_back(str);
        str.erase(str.begin());
    }
    sort(vect.begin(),vect.end(),mycomp);
    for(vector<string>::iterator it=vect.begin();it!=vect.end();it++)
        cout<<*it<<'\n';
    return 0;
}
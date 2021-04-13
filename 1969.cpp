#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const string& lhs, const string&rhs) const
  {
    if (reverse) return (lhs.compare(rhs));
    else return (!lhs.compare(rhs));
  }
};
int main()
{
    /*ifstream myfile;
    ofstream out;
    myfile.open("input.txt");
    out.open("output.txt");
    */
    priority_queue<string, vector<string>, mycomparison > q;
    int n,m;
    string hd;
    vector<string> vs;
    //myfile>>n;
    //myfile>>m;
    cin>>n;
    cin>>m;
    int alpha[50][26];//first index:order of indexth column
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<26;j++)
        {
            alpha[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        string temp;
        //myfile>>temp;
        cin>>temp;
        vs.push_back(temp);
        for(int j=0;j<m;j++)
        {
            alpha[j][vs[i][j]-65]++;
        }
    }
    int max_alpha=0;
    int max_index=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<26;j++)
       {
            if(max_alpha<alpha[i][j])
            {
                max_alpha=alpha[i][j];
                max_index=j;
            }
       }
       //make the s that fits the condition//HD
       if(max_alpha==1)
       {
           hd.push_back(max_index+65);
       }
       else
       {
           hd.push_back(max_index+65);
       }
       max_alpha=0;
    }
   // out<<hd<<'\n';
    int HamDis=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(hd[j]!=vs[i][j])
            {
                HamDis++;
            }
        }
    }   
   // out<<HamDis;
   cout<<hd<<'\n'<<HamDis;
}
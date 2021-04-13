#include <iostream>
#include <list>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int a;
	string str;
	cin>>str;
	cin>>a;
	char com;
	char c;
	list<char> front(str.begin(),str.end());
	list<char> back;
	for(int i=0;i<a;i++)
	{
		cin>>com;
		switch(com)
		{
			case 'L':
			if(front.size()==0)
				break;
			else
				back.push_front(front.back());
				front.pop_back();
			break;
			case 'D':
			if(back.size()==0)
				break;
			else
				front.push_back(back.front());
				back.pop_front();
			break;
			case 'B':
				if(front.size()==0)
					break;
				else
					front.pop_back();
				//cout<<&it<<'\n';
			break;
			case 'P':
			 cin>>c;
			 front.push_back(c);
			break;
			default:
			break;
		}
	}
	for(list<char>::iterator it=front.begin(); it!=front.end();it++)
		cout<<*it;
	for(list<char>::iterator it=back.begin(); it!=back.end();it++)
		cout<<*it;
	return 0;
}
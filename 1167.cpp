#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <utility>
using namespace std;
class node
{
public:
    vector<pair<int, int>> linked;
    int number;
    priority_queue<int> local_max;
};
node nl[100001];
priority_queue<int> global_max;
void find(int, node &);
int main()
{
    int t;
    int a, b;
    int n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        while (1)
        {
            cin >> a;
            if (a == -1)
                break;
            cin >> b;
            nl[n].linked.push_back(pair<int, int>(a, b));
        }
    }
}
void find(int came_from, node &cur)
{
}
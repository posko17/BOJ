#include <iostream>
#include <vector>
#include <fstream>
#include <list>
using namespace std;
class node
{
public:
    node()
    {
        depth = 0;
        parent = 0;
        value = 0;
    }
    list<int> linked;
    int parent;
    int value;
    int depth;
};
int count = 1;
node n[100001];
void find(node &, int);
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t;
    cin >> t;
    int a, b;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        n[a].value = a;
        n[b].value = b;
        n[a].linked.push_back(b);
        n[b].linked.push_back(a);
    }
    n[1].parent = 1;
    find(n[1], 1);
    for (int i = 2; i <= t; i++)
    {
        cout << n[i].parent << '\n';
    }
    return 0;
}
void find(node &cur, int d)
{
    if (cur.linked.size() == 0)
        return;
    cur.depth = d;
    for (list<int>::iterator it = cur.linked.begin(); it != cur.linked.end(); it++)
    {
        n[*it].parent = cur.value;
        n[*it].linked.remove(cur.value);
        find(n[*it], d + 1);
    }
    return;
}
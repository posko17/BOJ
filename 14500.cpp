#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <utility>
using namespace std;
int v[501][501];
vector<pair<int, int>> s[501][501];
priority_queue<int> q;
void search(int r, int c, int count, int sum);
int row, col;
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> v[i][j];
            s[i][j].push_back(make_pair(i, j));
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            search(i, j, 0, 0);
        }
    }
    cout << q.top();
    return 0;
}
void search(int r, int c, int count, int sum)
{
    if (r < 0 || c < 0 || r >= row || c >= col)
    {
        return;
    }
    if (count == 4)
    {
        q.push(sum);
        return;
    }

    sum += v[r][c];
    //
    switch (d)
    {
    case 1:
        search(r, c - 1, count + 1, sum, 3);
        search(r + 1, c, count + 1, sum, 1);
        search(r, c + 1, count + 1, sum, 2);
        break;
    case 2:
        search(r - 1, c, count + 1, sum, 4);
        search(r + 1, c, count + 1, sum, 1);
        search(r, c + 1, count + 1, sum, 2);
        break;
    case 3:
        search(r - 1, c, count + 1, sum, 4);
        search(r, c - 1, count + 1, sum, 3);
        search(r + 1, c, count + 1, sum, 1);
        break;
    case 4:
        search(r - 1, c, count + 1, sum, 4);
        search(r, c - 1, count + 1, sum, 3);
        search(r, c + 1, count + 1, sum, 2);
        break;
    default:
        search(r - 1, c, count + 1, sum, 4);
        search(r, c - 1, count + 1, sum, 3);
        search(r + 1, c, count + 1, sum, 1);
        search(r, c + 1, count + 1, sum, 2);
        break;
    }

    return;
}
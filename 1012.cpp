#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class rad
{
public:
    int val;
    bool is_checked;

    rad(int val_)
    {
        val = val_;
        is_checked = false;
    }
};
int count = 0;
vector<vector<rad>> v;
int r, c, k;
void check_rad(int a, int b)
{
    //up
    bool up = false, down = false, left = false, right = false;
    if (a < 0 || a >= r || b < 0 || b >= c)
    {
        return;
    }
    if (v[a][b].is_checked || v[a][b].val == -1)
    {
        return;
    }
    v[a][b].is_checked = true;
    if (a - 1 < 0)
    {
        up = true;
    }
    else if (v[a - 1][b].is_checked || v[a - 1][b].val == -1)
    {
        up = true;
    }
    else
    {
        check_rad(a - 1, b);
    }

    //down
    if (a + 1 >= r)
    {
        down = true;
    }
    else if (v[a + 1][b].is_checked || v[a + 1][b].val == -1)
    {
        down = true;
    }
    else
    {
        check_rad(a + 1, b);
    }

    //left
    if (b - 1 < 0)
    {
        left = true;
    }
    else if (v[a][b - 1].is_checked || v[a][b - 1].val == -1)
    {
        left = true;
    }
    else
    {
        check_rad(a, b - 1);
    }

    //right
    if (b + 1 >= c)
    {
        right = true;
    }
    else if (v[a][b + 1].is_checked || v[a][b + 1].val == -1)
    {
        right = true;
    }
    else
    {
        check_rad(a, b + 1);
    }
    if (up && down && left && right)
    {
        count++;
    }
    return;
}
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t;
    for (int a = 0; a < 50; a++)
    {
        vector<rad> s;
        v.push_back(s);
        for (int b = 0; b < 50; b++)
        {
            rad temp(-1);
            v[a].push_back(temp);
        }
    }
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        count = 0;
        for (int a = 0; a < 50; a++)
        {
            for (int b = 0; b < 50; b++)
            {
                v[a][b].is_checked = false;
                v[a][b].val = -1;
            }
        }
        cin >> c >> r >> k;
        for (int j = 0; j < k; j++)
        {
            int a, b;
            cin >> b >> a;
            v[a][b].val = 1;
        }

        //all fiiled
        for (int a = 0; a < r; a++)
        {
            for (int b = 0; b < c; b++)
            {
                check_rad(a, b);
            }
        }
        cout << count << '\n';
    }
}

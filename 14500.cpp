#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int MAX = 500;

typedef struct dir
{
    int r, c;
} DIR;
DIR moveDir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool is_visited[MAX][MAX];
int mat[MAX][MAX];
int row, col;

int DFS(int r, int c, int count)
{
    if (count == 4)
        return mat[r][c];
    int nextr, nextc;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        nextr = r + moveDir[i].r;
        nextc = c + moveDir[i].c;
        if (nextr >= 0 && nextr < row && nextc >= 0 && nextc < col && !is_visited[nextr][nextc])
        {
            is_visited[nextr][nextc] = true;
            sum = max(sum, mat[r][c] + DFS(nextr, nextc, count + 1));
            is_visited[nextr][nextc] = false;
        }
    }
    return sum;
}

int fuck(int r, int c)
{
    int sum = 0;
    //ㅓ
    if (r >= 1 && c >= 1 && r < row - 1)
    {
        sum = max(sum, mat[r][c] + mat[r - 1][c] + mat[r][c - 1] + mat[r + 1][c]);
    }
    //ㅗ
    if (r >= 1 && c >= 1 && c < col - 1)
    {
        sum = max(sum, mat[r][c] + mat[r - 1][c] + mat[r][c - 1] + mat[r][c + 1]);
    }
    //ㅏ
    if (r >= 1 && c < col - 1 && r < row - 1)
    {
        sum = max(sum, mat[r][c] + mat[r - 1][c] + mat[r + 1][c] + mat[r][c + 1]);
    }
    //ㅜ
    if (c < col - 1 && c >= 1 && r < row - 1)
    {
        sum = max(sum, mat[r][c] + mat[r][c - 1] + mat[r][c + 1] + mat[r + 1][c]);
    }

    return sum;
}

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    int sum = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            is_visited[i][j] = true;
            sum = max(sum, DFS(i, j, 1));
            sum = max(sum, fuck(i, j));
            is_visited[i][j] = false;
        }

    cout << sum;
    return 0;
}

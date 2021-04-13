#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int b[5][5];
    int s[5][5];
    int check[12] = {0};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> s[i][j];
        }
    }
    int count = 0;
    int binggo = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            count++;
            //cin >> s[i][j];
            for (int a = 0; a < 5; a++)
            {
                for (int c = 0; c < 5; c++)
                {
                    if (s[i][j] == b[a][c])
                    {
                        b[a][c] = 0;
                    }
                }
            }
            //check it yo
            //bingogogogo
            for (int a = 0; a < 5; a++)
            {
                bool rr = true;
                bool cc = true;
                for (int c = 0; c < 5; c++)
                {
                    if (0 != b[a][c])
                    {
                        rr = false;
                    }
                }
                if (rr)
                {
                    check[a] = 1;
                }
                for (int c = 0; c < 5; c++)
                {
                    if (0 != b[c][a])
                    {
                        cc = false;
                    }
                }
                if (cc)
                {
                    check[a + 5] = 1;
                }
                if (b[0][0] == 0 && b[1][1] == 0 && b[2][2] == 0 && b[3][3] == 0 && b[4][4] == 0)
                {
                    check[10] = 1;
                }
                if (b[0][4] == 0 && b[1][3] == 0 && b[2][2] == 0 && b[3][1] == 0 && b[4][0] == 0)
                {
                    check[11] = 1;
                }
                int max = 0;
                for (int hh = 0; hh < 12; hh++)
                {
                    if (check[hh] == 1)
                    {
                        max++;
                    }
                }
                if (max >= 3)
                {
                    cout << count;
                    return 0;
                }
            }
        }
    }
}
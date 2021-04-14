#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class sector
{
public:
    sector(int s)
    {
        a = 1;
        b = 2;
        c = 3;
        d = 4;
        sector_ = s;
        init_sector_ = s;
    }
    int init_arr[50][50];
    int init_sector_;
    int a, b, c, d;
    int sector_;
};
int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int n, m, r;
    cin >> n >> m >> r;
    sector s1(1), s2(2), s3(3), s4(4), empty(0);
    vector<sector> v;
    // v.push_back(empty);
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    v.push_back(s4);
    for (int i = 0, a; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a;
            if (i < n / 2 && j < m / 2)
            { //sector 1
                v[0].init_arr[i][j] = a;
            }
            else if (i < n / 2 && j >= m / 2)
            { //sector 2
                v[1].init_arr[i][j - m / 2] = a;
            }
            else if (i >= n / 2 && j < m / 2)
            { //sector 4
                v[3].init_arr[i - n / 2][j] = a;
            }
            else
            { //sector 3
                v[2].init_arr[i - n / 2][j - m / 2] = a;
            }
        }
    }
    int op;
    for (int j = 0; j < r; j++)
    {
        cin >> op;
        //operation start
        for (int i = 0; i < 4; i++)
        {
            switch (op)
            {
            case 1:
                if (v[i].a == 1)
                {
                    v[i].a = 4;
                }
                else if (v[i].a == 2)
                {
                    v[i].a = 3;
                }
                else if (v[i].a == 3)
                {
                    v[i].a = 2;
                }
                else
                {
                    v[i].a = 1;
                }

                ////

                if (v[i].b == 1)
                {
                    v[i].b = 4;
                }
                else if (v[i].b == 2)
                {
                    v[i].b = 3;
                }
                else if (v[i].b == 3)
                {
                    v[i].b = 2;
                }
                else
                {
                    v[i].b = 1;
                }

                ////

                if (v[i].c == 1)
                {
                    v[i].c = 4;
                }
                else if (v[i].c == 2)
                {
                    v[i].c = 3;
                }
                else if (v[i].c == 3)
                {
                    v[i].c = 2;
                }
                else
                {
                    v[i].c = 1;
                }

                ////

                if (v[i].d == 1)
                {
                    v[i].d = 4;
                }
                else if (v[i].d == 2)
                {
                    v[i].d = 3;
                }
                else if (v[i].d == 3)
                {
                    v[i].d = 2;
                }
                else
                {
                    v[i].d = 1;
                }
                switch (v[i].sector_)
                {
                case 1:
                    v[i].sector_ = 4;
                    break;
                case 2:
                    v[i].sector_ = 3;
                    break;
                case 3:
                    v[i].sector_ = 2;
                    break;
                case 4:
                    v[i].sector_ = 1;
                    break;
                default:
                    break;
                }
                break;
            case 2:
                if (v[i].a == 1)
                {
                    v[i].a = 2;
                }
                else if (v[i].a == 2)
                {
                    v[i].a = 1;
                }
                else if (v[i].a == 3)
                {
                    v[i].a = 4;
                }
                else
                {
                    v[i].a = 3;
                }

                ////

                if (v[i].b == 1)
                {
                    v[i].b = 2;
                }
                else if (v[i].b == 2)
                {
                    v[i].b = 1;
                }
                else if (v[i].b == 3)
                {
                    v[i].b = 4;
                }
                else
                {
                    v[i].b = 3;
                }

                ////

                if (v[i].c == 1)
                {
                    v[i].c = 2;
                }
                else if (v[i].c == 2)
                {
                    v[i].c = 1;
                }
                else if (v[i].c == 3)
                {
                    v[i].c = 4;
                }
                else
                {
                    v[i].c = 3;
                }

                ////

                if (v[i].d == 1)
                {
                    v[i].d = 2;
                }
                else if (v[i].d == 2)
                {
                    v[i].d = 1;
                }
                else if (v[i].d == 3)
                {
                    v[i].d = 4;
                }
                else
                {
                    v[i].d = 3;
                }
                switch (v[i].sector_)
                {
                case 1:
                    v[i].sector_ = 2;
                    break;
                case 2:
                    v[i].sector_ = 1;
                    break;
                case 3:
                    v[i].sector_ = 4;
                    break;
                case 4:
                    v[i].sector_ = 3;
                    break;
                default:
                    break;
                }
                break;
            case 3:
                if (v[i].a == 1)
                {
                    v[i].a = 2;
                }
                else if (v[i].a == 2)
                {
                    v[i].a = 3;
                }
                else if (v[i].a == 3)
                {
                    v[i].a = 4;
                }
                else
                {
                    v[i].a = 1;
                }

                ////

                if (v[i].b == 1)
                {
                    v[i].b = 2;
                }
                else if (v[i].b == 2)
                {
                    v[i].b = 3;
                }
                else if (v[i].b == 3)
                {
                    v[i].b = 4;
                }
                else
                {
                    v[i].b = 1;
                }

                ////

                if (v[i].c == 1)
                {
                    v[i].c = 2;
                }
                else if (v[i].c == 2)
                {
                    v[i].c = 3;
                }
                else if (v[i].c == 3)
                {
                    v[i].c = 4;
                }
                else
                {
                    v[i].c = 1;
                }

                ////

                if (v[i].d == 1)
                {
                    v[i].d = 2;
                }
                else if (v[i].d == 2)
                {
                    v[i].d = 3;
                }
                else if (v[i].d == 3)
                {
                    v[i].d = 4;
                }
                else
                {
                    v[i].d = 1;
                }
                switch (v[i].sector_)
                {
                case 1:

                    v[i].sector_ = 2;
                    break;
                case 2:

                    v[i].sector_ = 3;
                    break;
                case 3:

                    v[i].sector_ = 4;
                    break;
                case 4:

                    v[i].sector_ = 1;
                    break;
                default:
                    break;
                }
                break;
            case 4:
                if (v[i].a == 1)
                {
                    v[i].a = 4;
                }
                else if (v[i].a == 2)
                {
                    v[i].a = 1;
                }
                else if (v[i].a == 3)
                {
                    v[i].a = 2;
                }
                else
                {
                    v[i].a = 3;
                }

                ////

                if (v[i].b == 1)
                {
                    v[i].b = 4;
                }
                else if (v[i].b == 2)
                {
                    v[i].b = 1;
                }
                else if (v[i].b == 3)
                {
                    v[i].b = 2;
                }
                else
                {
                    v[i].b = 3;
                }

                ////

                if (v[i].c == 1)
                {
                    v[i].c = 4;
                }
                else if (v[i].c == 2)
                {
                    v[i].c = 1;
                }
                else if (v[i].c == 3)
                {
                    v[i].c = 2;
                }
                else
                {
                    v[i].c = 3;
                }

                ////

                if (v[i].d == 1)
                {
                    v[i].d = 4;
                }
                else if (v[i].d == 2)
                {
                    v[i].d = 1;
                }
                else if (v[i].d == 3)
                {
                    v[i].d = 2;
                }
                else
                {
                    v[i].d = 3;
                }
                switch (v[i].sector_)
                {
                case 1:

                    v[i].sector_ = 4;
                    break;
                case 2:

                    v[i].sector_ = 1;
                    break;
                case 3:

                    v[i].sector_ = 2;
                    break;
                case 4:

                    v[i].sector_ = 3;
                    break;
                default:
                    break;
                }
                break;
            case 5:
                switch (v[i].sector_)
                {
                case 1:

                    v[i].sector_ = 2;
                    break;
                case 2:

                    v[i].sector_ = 3;
                    break;
                case 3:

                    v[i].sector_ = 4;
                    break;
                case 4:

                    v[i].sector_ = 1;
                    break;
                default:
                    break;
                }
                break;
            case 6:
                switch (v[i].sector_)
                {
                case 1:

                    v[i].sector_ = 4;
                    break;
                case 2:

                    v[i].sector_ = 1;
                    break;
                case 3:

                    v[i].sector_ = 2;
                    break;
                case 4:

                    v[i].sector_ = 3;
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
    }
    int final_arr[100][100];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            final_arr[i][j] = 0;
        }
    }
    for (int i = 0; i < 4; i++)
    { //vector index
        switch (v[i].sector_)
        {
        case 1: //sector 1
            //
            switch (v[i].a)
            {
            case 1:
                if (v[i].b == 2)
                { //a b
                    //d c
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[r][c] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 4)
                { //a d
                    //b c
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[c][r] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            case 2:
                if (v[i].b == 3)
                { //d a
                    //c b
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[c][n / 2 - 1 - r] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 1)
                { //b a
                    //c d
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[r][m / 2 - 1 - c] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            case 3:
                if (v[i].b == 2)
                { //c b
                    //d a
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[m / 2 - 1 - c][n / 2 - 1 - r] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 4)
                { //c d
                    //b a
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[n / 2 - 1 - r][m / 2 - c - 1] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            case 4:
                if (v[i].b == 3)
                { //d c
                    //a b
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[n / 2 - 1 - r][c] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 1)
                { //b c
                    //a d
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[m / 2 - 1 - c][r] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            default:
                break;
            }

            break;
        case 2: //sector 2
            switch (v[i].a)
            {
            case 1:
                if (v[i].b == 2)
                { //a b
                    //d c
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[r][c + m / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 4)
                { //a d
                    //b c
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[c][r + n / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            case 2:
                if (v[i].b == 3)
                { //d a
                    //c b
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[c][n / 2 - 1 - r + n / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 1)
                { //b a
                    //c d
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[r][m / 2 - 1 - c + m / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            case 3:
                if (v[i].b == 2)
                { //c b
                    //d a
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[m / 2 - 1 - c][n / 2 - 1 - r + n / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 4)
                { //c d
                    //b a
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[n / 2 - 1 - r][m / 2 - c - 1 + m / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            case 4:
                if (v[i].b == 3)
                { //d c
                    //a b
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[n / 2 - 1 - r][c + m / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 1)
                { //b c
                    //a d
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[m / 2 - 1 - c][r + n / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            default:
                break;
            }

            break;
        case 3: //sector 3
            switch (v[i].a)
            {
            case 1:
                if (v[i].b == 2)
                { //a b
                    //d c
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[r + n / 2][c + m / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 4)
                { //a d
                    //b c
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[c + m / 2][r + n / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            case 2:
                if (v[i].b == 3)
                { //d a
                    //c b
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[c + m / 2][n / 2 - 1 - r + n / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 1)
                { //b a
                    //c d
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[r + n / 2][m / 2 - 1 - c + m / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            case 3:
                if (v[i].b == 2)
                { //c b
                    //d a
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[m / 2 - 1 - c + m / 2][n / 2 - 1 - r + n / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 4)
                { //c d
                    //b a
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[n / 2 - 1 - r + n / 2][m / 2 - c - 1 + m / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            case 4:
                if (v[i].b == 3)
                { //d c
                    //a b
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[n / 2 - 1 - r + n / 2][c + m / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 1)
                { //b c
                    //a d
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[m / 2 - 1 - c + m / 2][r + n / 2] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            default:
                break;
            }

            break;
        case 4: //sector 4
            switch (v[i].a)
            {
            case 1:
                if (v[i].b == 2)
                { //a b
                    //d c
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[r + n / 2][c] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 4)
                { //a d
                    //b c
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[c + m / 2][r] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            case 2:
                if (v[i].b == 3)
                { //d a
                    //c b
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[c + m / 2][n / 2 - 1 - r] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 1)
                { //b a
                    //c d
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[r + n / 2][m / 2 - 1 - c] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            case 3:
                if (v[i].b == 2)
                { //c b
                    //d a
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[m / 2 - 1 - c + m / 2][n / 2 - 1 - r] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 4)
                { //c d
                    //b a
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[n / 2 - 1 - r + n / 2][m / 2 - c - 1] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            case 4:
                if (v[i].b == 3)
                { //d c
                    //a b
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[n / 2 - 1 - r + n / 2][c] = v[i].init_arr[r][c];
                        }
                    }
                }
                else if (v[i].b == 1)
                { //b c
                    //a d
                    for (int r = 0; r < n / 2; r++)
                    {
                        for (int c = 0; c < m / 2; c++)
                        {
                            final_arr[m / 2 - 1 - c + m / 2][r] = v[i].init_arr[r][c];
                        }
                    }
                }
                else
                {
                    cout << "error!\n";
                }
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (final_arr[i][j] != 0)
                cout << final_arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
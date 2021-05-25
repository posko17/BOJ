#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAX = 101;

int n, pl, mi, mul, di;
int arr[MAX];
ll cal_max = -1e9, cal_min = 1e9;
void cal(int, int, int, int, int, ll);

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cin >> pl >> mi >> mul >> di;

    cal(1, pl, mi, mul, di, arr[1]);

    cout << cal_max << '\n'
         << cal_min;
    return 0;
}

void cal(int index, int pl, int mi, int mul, int di, ll result)
{
    if (pl == 0 && mi == 0 && mul == 0 && di == 0)
    {
        cal_max = max(result, cal_max);
        cal_min = min(result, cal_min);
        return;
    }
    //plus
    if (pl > 0)
        cal(index + 1, pl - 1, mi, mul, di, result + arr[index + 1]);
    //minus
    if (mi > 0)
        cal(index + 1, pl, mi - 1, mul, di, result - arr[index + 1]);
    //mul
    if (mul > 0)
        cal(index + 1, pl, mi, mul - 1, di, result * arr[index + 1]);
    //div
    if (di > 0 || arr[index + 1] != 0)
        cal(index + 1, pl, mi, mul, di - 1, result / arr[index + 1]);
    return;
}
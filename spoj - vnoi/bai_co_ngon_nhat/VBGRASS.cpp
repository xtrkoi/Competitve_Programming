#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef long long ll;

const int maxn = 102;

int r, c, bai_co[maxn][maxn], da_di[maxn][maxn], cnt = 0;

void preset()
{
    for (int i = 0; i <= r + 1; i++)
        for (int j = 0; j <= c + 1; j++)
            bai_co[i][j] = da_di[i][j] = 0;
}

void input()
{
    string tmp;
    for (int i = 1; i <= r; i++)
    {
        cin >> tmp;
        for (int j = 1; j <= c; j++)
            if (tmp[j - 1] == '#')
                bai_co[i][j] = 1;
    }
}

void run()
{
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            if (bai_co[i][j] && !da_di[i][j])
            {
                cnt++;
                for (int u = -1; u <= 1; u++)
                    for (int v = -1; v <= 1; v++)
                    {
                        if ((u == 0 && v == 0) || (u != 0 && v != 0))
                            continue;
                        if (bai_co[i + u][j + v])
                            da_di[i + u][j + v] = 1;
                    }
            }
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("vbgrass.inp", "r", stdin);
    freopen("vbgrass.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    preset();
    input();
    run();
    cout << cnt;
    return 0;
}
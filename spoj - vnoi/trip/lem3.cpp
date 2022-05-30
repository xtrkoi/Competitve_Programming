#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef vector<int> vi;

const int maxn = 20, INF = 2e9;
int n;
vector<vi> c(maxn, vi(maxn)), f(70000, vi(maxn, 0));

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
}

int find_cost(int schedule, int end)
{
    if (schedule == 0)
        return 0;
    int &res = f[schedule][end];
    if (res == 0)
    {
        res = INF;
        for (int i = 0; i < n; i++)
            if (schedule & (1 << i))
                res = min(res, find_cost(schedule & ~(1 << i), i) + c[i][end]);
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("lem3.inp", "r", stdin);
    freopen("lem3.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    int res = INF;
    for (int i = 0; i < n; i++)
        res = min(res, find_cost((1 << n) - 1, i));
    cout << res;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair

const int INF = 2e9;
int m, n, a[100005], b[100005];
vector<int> dp;
pair<int, int> c[100005];

int find(int x)
{
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (x == c[mid].X)
        {
            return c[mid].Y;
        }
        else if (x > c[mid].X)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

void run()
{
    for (int i = 1; i <= m; i++)
    {
        int j = find(a[i]);
        if (j < 0)
            continue;
        if (dp.empty() || dp.back() < j)
            dp.pb(j);
        else
        {
            int k = lower_bound(dp.begin(), dp.end(), j) - dp.begin();
            dp[k] = j;
        }
    }
    cout << dp.size();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("dplcsnlog.inp", "r", stdin);
    freopen("dplcsnlog.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        c[i] = mp(b[i], i);
    }
    sort(c + 1, c + n + 1);
    run();
    return 0;
}
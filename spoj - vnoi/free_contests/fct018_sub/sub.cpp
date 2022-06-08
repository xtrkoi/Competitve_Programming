#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 2, INF = 2e9;
int t, n;
int arr[maxn], dp[maxn];

void run()
{
    int res1 = 0, res2 = -INF, cnt = 0, mx = -INF;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= 0)
        {
            cnt++;
            res1 += arr[i];
        }
        else
            mx = max(mx, arr[i]);
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        res2 = max(res2, dp[i]);
    }
    if (cnt == 0)
        res1 = mx;
    cout << res1 << " " << res2 << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("sub.inp", "r", stdin);
    freopen("sub.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
        run();
    return 0;
}
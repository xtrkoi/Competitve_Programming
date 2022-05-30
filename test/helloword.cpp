#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll m, n, t, k, s, a[1005][1005], Max = -9999999999, f[1005][1005];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[j][i] = max(f[j - 1][i - 1], max(f[j][i - 1], f[j + 1][i - 1])) + a[j][i];
            Max = max(Max, f[j][i]);
        }
    cout << Max;
    return 0;
}
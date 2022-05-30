#include <bits/stdc++.h>
using namespace std;
int t, m, n, k, dp[102][102][102];
string a, b, c;

void initialize()
{
    for (int i = 0; i <= 101; i++)
        dp[i][0][0] = dp[0][i][0] = dp[0][0][i] = 0;
}

void run()
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for (int h = 1; h <= k; h++)
            {
                if (a[i - 1] == b[j - 1] && b[j - 1] == c[h - 1])
                    dp[i][j][h] = dp[i - 1][j - 1][h - 1] + 1;
                else
                    dp[i][j][h] = max(dp[i - 1][j][h], max(dp[i][j - 1][h], dp[i][j][h - 1]));
            }
    cout << dp[m][n][k] << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("dplcs3s.inp", "r", stdin);
    freopen("dplcs3s.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    initialize();
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> k >> a >> b >> c;
        run();
    }
    return 0;
}
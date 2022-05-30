#include <bits/stdc++.h>
using namespace std;

int m, n, dp[3033][3033];
string s, t;

void initialize()
{
    for (int i = 0; i <= 3031; i++)
        dp[i][0] = dp[0][i] = i;
}

void run()
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    cout << dp[m][n];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("dplcsdel.inp", "r", stdin);
    freopen("dplcsdel.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    m = s.size();
    n = t.size();
    initialize();
    run();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int m, n, dp[1012][1012], cnt = 0;
string a, b;

void initialize()
{
    for (int i = 0; i <= 1011; i++)
        dp[i][0] = dp[0][i] = 0;
}

void run()
{
    for (int i = 1; i <= m; i++)
    {
        bool inc = false;
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (!inc)
                {
                    inc = true;
                    cnt++;
                }
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << m + n + cnt - dp[m][n] * 3;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("dplcsad.inp", "r", stdin);
    freopen("dplcsad.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    m = a.size();
    n = b.size();
    initialize();
    run();
    return 0;
}
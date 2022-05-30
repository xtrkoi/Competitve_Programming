#include <bits/stdc++.h>
using namespace std;

const int maxn = 5002;
int n, m, a[maxn], b[maxn], dp_lcs[maxn][maxn], dp_lis1[maxn], dp_lis2[maxn];

void initialize()
{
    for (int i = 0; i <= 1001; i++)
    {
        dp_lcs[0][i] = dp_lcs[i][0] = 0;
        dp_lis1[i] = dp_lis2[i] = 1;
    }
}

void lis(int arr[], int (&dp)[maxn], int len)
{
    for (int i = 2; i <= len; i++)
        for (int j = 1; j < i; j++)
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
}

void run()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j] && dp_lis1[i] == dp_lis2[i])
                dp_lcs[i][j] = dp_lcs[i - 1][j - 1];
            else
                dp_lcs[i][j] = max(dp_lcs[i - 1][j], dp_lcs[i][j - 1]);
        }
    cout << dp_lcs[n][m];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("dplcsic.inp", "r", stdin);
    freopen("dplcsic.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    initialize();
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    lis(a, dp_lis1, n);
    lis(b, dp_lis2, m);
    // run();
    for (int i = 1; i <= n; i++)
        cout << dp_lis1[i] << " ";
    cout << "\n";
    // for (int i = 1; i <= m; i++)
    //     cout << dp_lis2[i] << " ";
    return 0;
}
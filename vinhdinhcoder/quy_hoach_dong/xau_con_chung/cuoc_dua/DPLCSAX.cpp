#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef pair<int, int> ii;

int t, dp[2002][2002];
vi prim(2002), comp(2002);

void initialize()
{
    for (int i = 0; i <= 2000; i++)
        dp[i][0] = dp[0][i] = 0;
}

int find_lcs(int m, int n)
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (prim[i] == comp[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    return dp[m][n];
}

void run()
{
    int i = 1, stop, res = 0;
    while (cin >> prim[i])
    {
        if (prim[i] == 0)
            break;
        i++;
    }
    while (cin >> comp[1])
    {
        if (comp[1] == 0)
            break;
        int j = 2;
        while (cin >> comp[j])
        {
            if (comp[j] == 0)
                break;
            j++;
        }
        res = max(res, find_lcs(i - 1, j - 1));
    }
    cout << res << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("dplcsax.inp", "r", stdin);
    freopen("dplcsax.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    initialize();
    cin >> t;
    while (t--)
        run();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define sz(A) (int)A.size()

typedef vector<int> vi;

const int maxn = 2e3 + 2;
string a, b;
vector<vi> dp(maxn, vi(maxn, 0));

int main()
{
#ifndef ONLINE_JUDGE
    freopen("qbstr.inp", "r", stdin);
    freopen("qbstr.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    for (int i = 1; i <= sz(a); i++)
        for (int j = 1; j <= sz(b); j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    cout << dp[sz(a)][sz(b)];
    return 0;
}
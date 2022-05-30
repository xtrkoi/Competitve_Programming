#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
// dp[i, j]: i -> steps remaining, j -> distance from origin
ll dp[15][15];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("mbeewalk.inp", "r", stdin);
    freopen("mbeewalk.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[0][0] = 0;
    dp[1][1] = 6;
    ll expo = 4;
    for (int i = 2; i <= 15; i++)
    {
        dp[i][i] = dp[i - 1][i - 1] * expo;
        expo *= 2;
    }
    for (int i = 1; i <= 15; i++)
        for (int j = 0; j < i; j++)
            dp[j][i] = 0;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 1e6 + 2;
string a, b;
vi dp(maxn, 0);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("substr.inp", "r", stdin);
    freopen("substr.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    for (int i = 1, l = 0, r = 0; i < sz(a); i++)
    {
        if (i <= r)
            dp[i] = min(r - i + 1, dp[i - l]);
        while (i + dp[i] < sz(a) && a[dp[i]] == a[dp[i + 1]])
            dp[i]++;
        if (i + dp[i] - 1 > r)
            l = i, r = i + dp[i] - 1;
    }
    return 0;
}
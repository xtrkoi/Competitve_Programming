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

const int maxn = 103, maxw = 1e5 + 2;
int n, m;
vi val, wei;
vector<ll> dp(maxw);

void input()
{
    cin >> n >> m;
    int tmp_val, tmp_wei;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp_wei >> tmp_val;
        wei.pb(tmp_wei);
        val.pb(tmp_val);
    }
}

void run()
{
    for (int i = 0; i < n; i++)
        for (int j = m; j >= wei[i]; j--)
            dp[j] = max(dp[j], dp[j - wei[i]] + val[i]);
    cout << dp[m];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("knapsack1.inp", "r", stdin);
    freopen("knapsack1.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
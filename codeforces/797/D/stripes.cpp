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

const int maxn = 2e5 + 2;
int t, n, k;
string s;
vi dp(maxn);

void run()
{
    cin >> n >> k >> s;
    s = " " + s + " ";
    for (int i = 1; i <= n + 1; i++)
    {
        if (s[i] != s[i - 1])
        {
            if (s[i] != ' ')
                dp[i] = (s[i] == 'B' ? 1 : -1);
        }
        else
            dp[i] = (s[i] == 'B' ? dp[i - 1] + 1 : dp[i - 1] - 1);
        if (dp[i] >= k)
        {
            cout << "0\n";
            return;
        }
    }
    vi cprs;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] * dp[i - 1] < 0)
            cprs.pb(dp[i - 1]);
    }
    for (int i : cprs)
        cout << i << " ";
    cout << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("stripes.inp", "r", stdin);
    freopen("stripes.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
        run();
    return 0;
}
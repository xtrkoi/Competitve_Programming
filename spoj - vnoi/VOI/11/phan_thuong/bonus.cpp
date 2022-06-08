#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;

const int maxn = 1e3 + 2, INF = 2e9;
int n, k;
int arr[maxn][maxn], s[maxn][maxn], dp[maxn][maxn];

void input()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
}

void init()
{
    for (int i = 0; i <= n + 1; i++)
        s[0][i] = s[i][0] = s[n + 1][i] = s[i][n + 1] =
            dp[0][i] = dp[i][0] = dp[n + 1][i] = dp[i][n + 1] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + arr[i][j];
}

void run()
{
    int res = -INF;
    for (int i = k; i <= n; i++)
        for (int j = k; j <= n; j++)
            res = max(res, s[i][j] - s[i - k][j] - s[i][j - k] + s[i - k][j - k]);
    cout << res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("bonus.inp", "r", stdin);
    freopen("bonus.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    init();
    run();
    return 0;
}
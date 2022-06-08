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

int n;
vector<vi> arr(3);

void input()
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> tmp;
            arr[j].pb(tmp);
        }
    }
}

void run()
{
    vector<vi> dp(3, vi(n + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
            dp[j][i] = max(dp[(j + 1) % 3][i - 1], dp[(j + 2) % 3][i - 1]) + arr[j][i - 1];
    }
    int res = 0;
    for (int i = 0; i < 3; i++)
        res = max(res, dp[i][n]);
    cout << res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("vacation.inp", "r", stdin);
    freopen("vacation.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
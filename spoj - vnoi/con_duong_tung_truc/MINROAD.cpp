#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;

const int INF = 1e9;
vector<ii> arr, tcnt;
int n, a, b, res = INF;

void input()
{
    cin >> n >> a >> b;
    int tmp1, tmp2;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp1 >> tmp2;
        arr.pb(mp(tmp1, tmp2));
    }
    sort(arr.begin(), arr.end());
}

void subset_tree_count()
{
    if (arr[0].Y == 1)
        tcnt.pb(mp(1, 0));
    else
        tcnt.pb(mp(0, 1));

    for (int i = 1; i < n; i++)
    {
        if (arr[i].Y == 1)
            tcnt.pb(mp(tcnt[i - 1].X + 1, tcnt[i - 1].Y));
        else
            tcnt.pb(mp(tcnt[i - 1].X, tcnt[i - 1].Y + 1));
    }
}

void run()
{
    for (int i = 0; i < n; i++)
    {
        int j = lower_bound(tcnt.begin(), tcnt.end(), mp(tcnt[i - 1].X + a, tcnt[i - 1].Y + b)) - tcnt.begin();
        if (j != tcnt.end() - tcnt.begin())
            res = min(res, arr[j].X - arr[i - 1].X);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("minroad.inp", "r", stdin);
    freopen("minroad.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    subset_tree_count();
    run();
    if (res == INF)
        cout << "-1";
    else
        cout << res;
    return 0;
}
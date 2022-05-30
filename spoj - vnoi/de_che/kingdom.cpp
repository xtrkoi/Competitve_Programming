#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 102, maxw = 2002;
int n, m;
vi val(maxn), c(maxn), arr;
vector<vi> adj(maxn), dp(maxn, vi(maxn, 0));
vector<bool> seen(maxn, false);

void input()
{
    cin >> n >> m;
    for (int i = 2; i < n; i++)
        cin >> val[i];
    for (int i = 2; i < n; i++)
        cin >> c[i];
    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void bfs()
{
    queue<int> q;
    q.push(1);
    seen[1] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        arr.pb(u);
        for (int v : adj[u])
        {
            if (!seen[v])
            {
                seen[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("kingdom.inp", "r", stdin);
    freopen("kingdom.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    bfs();
    // int res = 0;
    // for (int i = 1; i <= n; i++)
    //     res = max(res, dp[i][m]);
    // cout << res;
    cout << dp[1][m];
    return 0;
}
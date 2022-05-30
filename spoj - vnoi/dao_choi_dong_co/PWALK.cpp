#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef pair<int, int> ii;
typedef vector<ii> vii;

const int maxn = 1e4 + 3;
int n, q, tmp = 0, res;
vector<vii> adj(maxn);
bool stop;

void input()
{
    cin >> n >> q;
    int a, b, w;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
}

void dfs(int u, int t, int p = -1)
{
    for (ii v : adj[u])
        if (v.X != p)
        {
            tmp += v.Y;
            if (v.X == t)
            {
                stop = true;
                res = tmp;
            }
            else
                dfs(v.X, t, u);
            if (stop)
                return;
            tmp -= v.Y;
        }
}

void run(int s, int t)
{
    stop = false;
    tmp = 0;
    dfs(s, t);
    cout << res << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("pwalk.inp", "r", stdin);
    freopen("pwalk.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        run(a, b);
    }
    return 0;
}
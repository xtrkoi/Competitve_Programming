#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

const int maxn = 1e5 + 2, INF = 2e9;
const ll VINF = LONG_LONG_MAX - 2;
int n, m;
vector<vii> adj(maxn);
vector<bool> seen(maxn);
vi d1(maxn), d2(maxn), res(maxn, INF);

void input()
{
    cin >> n >> m;
    int u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        adj[u].pb(mp(v, c));
        adj[v].pb(mp(u, c));
    }
}

void bfs(int st, vi &dis)
{
    queue<int> q;
    q.push(st);
    seen[st] = true;
    dis[st] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (ii v : adj[u])
        {
            if (!seen[v.X])
            {
                seen[v.X] = true;
                dis[v.X] = dis[u] + 1;
                q.push(v.X);
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("mecung.inp", "r", stdin);
    freopen("mecung.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    seen = vector<bool>(maxn, false);
    bfs(1, d1);

    seen = vector<bool>(maxn, false);
    bfs(n, d2);

    seen = vector<bool>(maxn, false);
    vi s[2];
    int i = 0;
    s[i].pb(1);
    seen[1] = true;
    for (int k = 1; k <= d1[n]; k++)
    {
        int mn = INF;
        for (int u : s[i])
            for (ii v : adj[u])
                if (!seen[v.X] && d1[v.X] + d2[v.X] == d1[n])
                    mn = min(mn, v.Y);
        for (int u : s[i])
            for (ii v : adj[u])
                if (!seen[v.X] && d1[v.X] + d2[v.X] == d1[n] && v.Y == mn)
                {
                    seen[v.X] = true;
                    s[1 - i].pb(v.X);
                    res[k] = v.Y;
                }
        s[i].clear();
        i = 1 - i;
    }
    cout << d1[n] << "\n";
    for (int i = 1; i <= d1[n]; i++)
        cout << res[i] << " ";
    return 0;
}

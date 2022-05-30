#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int maxv = 5e4 + 7, INF = 1e9;
int n, m, s, t, res = -INF;
bool find_path = false;
vector<bool> seen(maxv, false);
vector<ii> adj[maxv];
stack<int> stk;
vi dist(maxv, -INF);

void input()
{
    cin >> n >> m >> s >> t;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
    }
}

void dfs(int u)
{
    seen[u] = true;
    for (ii v : adj[u])
    {
        if (v.F == t)
            find_path = true;
        if (!seen[v.F])
            dfs(v.F);
    }
    stk.push(u);
}

void run()
{
    dfs(s);
    if (!find_path)
    {
        cout << "NO";
        return;
    }

    cout << "YES\n";

    dist[s] = 0;
    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();
        if (dist[u] != -INF)
            for (ii v : adj[u])
                dist[v.F] = max(dist[v.F], dist[u] + v.S);
    }
    cout << dist[t];
}

int main()
{
    freopen("maxpath.inp", "r", stdin);
    freopen("maxpath.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
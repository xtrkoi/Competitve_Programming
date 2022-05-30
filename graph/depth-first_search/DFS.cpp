#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef long long ll;
typedef pair<int, int> ii;

const int maxv = 1e5 + 2, maxe = 1e6 + 2;

int n, m, s, t, trace[maxv];
bool seen[maxv], stop = false;
vector<vector<int>> adj(maxv);
vector<ii> edges;

void input()
{
    cin >> n >> m >> s >> t;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        edges.pb(mp(u, v));
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < m; i++)
        adj[edges[i].X].pb(edges[i].Y);
}

void output()
{
    cout << s << " ";
    while (trace[s] != t)
    {
        cout << trace[s] << " ";
        s = trace[s];
    }
    cout << t;
}

void dfs(int u)
{
    seen[u] = true;
    for (int v = 0; v < sz(adj[u]); v++)
    {
        if (!seen[adj[u][v]])
        {
            trace[u] = adj[u][v];
            if (adj[u][v] == t)
            {
                output();
                exit(0);
            }
            dfs(adj[u][v]);
        }
    }
}

int main()
{
    freopen("dfs.inp", "r", stdin);
    freopen("dfs.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for (int i = 0; i <= n; i++)
        seen[i] = false;
    dfs(s);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;

const int maxv = 1e5 + 2;

int n, m, scc_cnt = 0;
vector<bool> seen(maxv, false);
vi scc_adj[maxv], scc[maxv];
stack<int> s;
struct node
{
    vi adj;
    vi rev_adj;
} g[maxv];

void input()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].adj.pb(v);
        g[v].rev_adj.pb(u);
    }
}

void dfs_1(int u)
{
    seen[u] = true;
    for (int v : g[u].adj)
        if (!seen[v])
            dfs_1(v);
    s.push(u);
}

void dfs_2(int u)
{
    seen[u] = true;
    scc[scc_cnt].pb(u);
    for (int v : g[u].rev_adj)
    {
        scc_adj[u].pb(v);
        if (!seen[v])
            dfs_2(v);
    }
}

void run()
{
    for (int i = 1; i <= n; i++)
        if (!seen[i])
            dfs_1(i);

    for (int i = 1; i <= n; i++)
        seen[i] = 0;

    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        if (!seen[v])
        {
            scc_cnt++;
            dfs_2(v);
        }
    }

    for (int i = 1; i <= scc_cnt; i++)
    {
        for (int j : scc[i])
            cout << j << " ";
        cout << "\n";
    }
}

int main()
{
    freopen("sconnect.inp", "r", stdin);
    freopen("sconnect.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}

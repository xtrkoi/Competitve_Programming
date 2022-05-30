#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef vector<bool> vb;

const int maxv = 1e5 + 5;
int n, m, res = 0;
vb seen(maxv, false);
vector<vi> adj(maxv);
stack<int> s;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
}

void topo_sort(int u)
{
    seen[u] == true;
    for (int v : adj[u])
        if (!seen[v])
            topo_sort(v);
    s.push(u);
}

void dfs(int u)
{
    static int trace = 0;
    seen[u] = true;
    for (int v : adj[u])
        if (!seen[v])
        {
            trace++;
            dfs(v);
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("longest_path.inp", "r", stdin);
    freopen("longest_path.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for (int i = 1; i <= n; i++)
        if (!seen[i])
            topo_sort(i);

    seen = vb(maxv, false);

    while (!s.empty())
    {
        if (!seen[s.top()])
            dfs(s.top());
        s.pop();
    }
    cout << res;
    return 0;
}
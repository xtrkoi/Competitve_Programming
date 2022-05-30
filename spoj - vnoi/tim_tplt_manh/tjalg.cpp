#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;

const int maxv = 1e4 + 5;
int n, m, cnt_scc = 0;
vi adj[maxv], disc(maxv, -1), low(maxv, 0);
vector<bool> seen(maxv, false);
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

void dfs(int u)
{
    static int time = 0;
    disc[u] = low[u] = ++time;
    seen[u] = true;
    s.push(u);
    for (int v : adj[u])
    {
        if (disc[v] < 0)
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (seen[v])
            low[u] = min(low[u], disc[v]);
    }

    if (low[u] == disc[u])
    {
        cnt_scc++;
        while (s.top() != u)
        {
            seen[s.top()] = false;
            s.pop();
        }
        seen[s.top()] = false;
        s.pop();
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("tjalg.inp", "r", stdin);
    freopen("tjalg.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for (int i = 1; i <= n; i++)
        if (disc[i] < 0)
            dfs(i);
    cout << cnt_scc;
    return 0;
}
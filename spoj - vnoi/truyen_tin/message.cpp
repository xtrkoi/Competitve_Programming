#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int maxv = 1007;

int n, m, cnt = 0;
vector<bool> seen(maxv);
vector<vector<int>> adj(maxv);
stack<int> s;

void input()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
    }
}

void pre_dfs(int u)
{
    seen[u] = true;
    for (int v : adj[u])
        if (!seen[v])
            pre_dfs(v);
    s.push(u);
}

void dfs(int u)
{
    seen[u] = true;
    for (auto v : adj[u])
        if (!seen[v])
            dfs(v);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("message.inp", "r", stdin);
    freopen("message.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    seen = vector<bool>(maxv, false);
    for (int i = 1; i <= n; i++)
        if (!seen[i])
            pre_dfs(i);
    seen = vector<bool>(maxv, false);
    while (!s.empty())
    {
        if (!seen[s.top()])
        {
            dfs(s.top());
            cnt++;
        }
        s.pop();
    }
    cout << cnt;
    return 0;
}
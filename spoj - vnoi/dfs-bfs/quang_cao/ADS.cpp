#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(A) A.size()

const int max_vertices = 2002;
vector<bool> seen(max_vertices, false);
vector<vector<int>> adj(max_vertices);
int n, m, cnt = 0;

void add_edge(int u, int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

void input()
{
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        add_edge(a, b);
    }
}

void dfs(int u)
{
    seen[u] = true;
    for (int v : adj[u])
        if (!seen[v])
            dfs(v);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("ads.inp", "r", stdin);
    freopen("ads.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for (int i = 1; i <= n; i++)
        if (!seen[i])
        {
            cnt++;
            dfs(i);
        }
    cout << cnt + m - n;
    return 0;
}
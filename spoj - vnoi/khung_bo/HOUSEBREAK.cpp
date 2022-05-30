#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int maxn = 5005;
int n, m;
vector<vector<int>> adj(maxn);
vector<int> arr;
vector<bool> visited(maxn, false);

void reset()
{
    arr.clear();
    for (int i = 0; i <= n; i++)
    {
        visited[i] = false;
        adj[i].clear();
    }
}

void add_edge(int u, int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

void run()
{
    int tmp, a, b;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            arr.pb(tmp);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            add_edge(a, b);
        }
    }
}
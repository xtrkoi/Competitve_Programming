#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

const int maxv = 1e4 + 2, maxe = 5e4 + 2;
int n, m, disc[maxv], low[maxv];
vector<ii> edge;
vector<vector<int>> adj(maxv);
vector<bool> isAP(maxv, false), seen(maxv, false);
vector<int> trace(maxv, -1);
int bridge_cnt = 0;

void add_edge(int u, int v)
{
    edge.pb(mp(u, v));
    adj[u].pb(v);
    adj[v].pb(u);
}

void input()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        add_edge(u, v);
    }
}

void find_AP_util(int u, int time, int parent)
{
    int children = 0;
    seen[u] = true;
    disc[u] = low[u] = time;
    for (auto v : adj[u])
    {
        if (!seen[v])
        {
            children++;
            find_AP_util(v, time + 1, u);
            low[u] = min(low[u], low[v]);
            if (parent != -1 && low[v] >= disc[u])
                isAP[u] = true;
        }
        else if (v != parent)
            low[u] = min(low[u], disc[v]);
    }
    if (parent == -1 && children > 1)
        isAP[u] = true;
}

void find_AP()
{
    for (int u = 1; u <= n; u++)
        find_AP_util(u, 1, -1);
    int cntAP = 0;
    for (int i = 1; i <= n; i++)
        if (isAP[i])
            cntAP++;
    cout << cntAP << " ";
}

void find_bridge_util(int u, int time)
{
    seen[u] = true;
    disc[u] = low[u] = time;
    for (auto v : adj[u])
    {
        if (!seen[v])
        {
            trace[v] = u;
            find_bridge_util(v, time + 1);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
                bridge_cnt++;
        }
        else if (v != trace[u])
            low[u] = min(low[u], disc[v]);
    }
}

void find_bridge()
{
    for (int i = 1; i <= n; i++)
        disc[i] = low[i] = seen[i] = 0;

    for (int i = 1; i <= n; i++)
        if (!seen[i])
            find_bridge_util(i, 1);
    cout << bridge_cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("graph_.inp", "r", stdin);
    freopen("graph_.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    find_AP();
    find_bridge();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxv = 1e5 + 5, maxe = 2e5 + 5;
int n, m;
vi disc(maxv, 0), low(maxv, 0);
vector<ii> bridge;
vector<vi> adj(maxv);
vector<bool> isAP(maxv, false), seen(maxv, false);
int AP_cnt = 0, cnt = 0;

void add_edge(int u, int v)
{
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

void find_AP_util(int u, int parent)
{
    int children = 0;
    seen[u] = true;
    disc[u] = low[u] = ++cnt;
    for (auto v : adj[u])
    {
        if (!seen[v])
        {
            children++;
            find_AP_util(v, u);
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
    cnt = 0;
    for (int i = 1; i <= n; i++)
        disc[i] = low[i] = seen[i] = 0;
    for (int u = 1; u <= n; u++)
        find_AP_util(u, -1);
    for (int i = 1; i <= n; i++)
        if (isAP[i])
            AP_cnt++;
}

void find_bridge_util(int u, int p = -1)
{
    disc[u] = low[u] = ++cnt;
    int double_edge = 0;
    for (auto v : adj[u])
    {
        if (v == p && !double_edge)
        {
            double_edge++;
            continue;
        }
        else if (!disc[v])
        {
            find_bridge_util(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
                bridge.pb(mp(u, v));
        }
        else
            low[u] = min(low[u], disc[v]);
    }
}

void find_bridge()
{
    cnt = 0;
    for (int i = 1; i <= n; i++)
        disc[i] = low[i] = 0;

    for (int i = 1; i <= n; i++)
        if (!seen[i])
            find_bridge_util(i);
}

void output()
{
    cout << bridge.size() << " " << AP_cnt << "\n";
    for (ii i : bridge)
        cout << i.X << " " << i.Y << "\n";
    for (int i = 1; i <= n; i++)
        if (isAP[i])
            cout << i << "\n";
}

int main()
{
    freopen("cut.inp", "r", stdin);
    freopen("cut.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    find_bridge();
    find_AP();
    output();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxv = 5e4 + 3, maxe = 1e5 + 3;
int n, m, cnt = 0;
vi disc(maxv, 0), low(maxv);
vector<vi> adj(maxv);
vector<ii> bridge;

void input()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void dfs(int u, int p = -1)
{
    disc[u] = low[u] = ++cnt;
    for (int v : adj[u])
    {
        if (!disc[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
            {
                if (u < v)
                    bridge.pb(mp(u, v));
                else
                    bridge.pb(mp(v, u));
            }
        }
        else if (v != p)
            low[u] = min(low[u], disc[v]);
    }
}

bool comp(const ii &a, const ii &b)
{
    return a.X < b.X || (a.X == b.X && a.Y < b.Y);
}

int main()
{
    freopen("bridges.inp", "r", stdin);
    freopen("bridges.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for (int i = 1; i <= n; i++)
        if (!disc[i])
            dfs(i);
    sort(bridge.begin(), bridge.end(), comp);
    cout << bridge.size() << "\n";
    for (ii i : bridge)
        cout << i.X << " " << i.Y << "\n";
    return 0;
}
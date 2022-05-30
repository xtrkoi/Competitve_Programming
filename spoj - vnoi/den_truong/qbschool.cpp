#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxn = 5002, INF = 2e9;
int n, m;
vector<vii> adj(maxn);
vi dis(maxn, INF);
vector<ll> paths(maxn, INF);
vector<bool> seen(maxn, false);

void input()
{
    cin >> n >> m;
    int k, u, v, l;
    for (int i = 0; i < m; i++)
    {
        cin >> k >> u >> v >> l;
        adj[u].pb(mp(v, l));
        if (k == 2)
            adj[v].pb(mp(u, l));
    }
}

void bfs()
{
    priority_queue<ii> q;
    q.push(mp(0, 1));
    dis[1] = 0;
    paths[1] = 1;
    while (!q.empty())
    {
        int u = q.top().Y;
        q.pop();
        if (seen[u])
            continue;
        seen[u] = true;
        for (ii v : adj[u])
        {
            int a = v.X, b = v.Y;
            if (dis[a] > dis[u] + b)
            {
                dis[a] = dis[u] + b;
                paths[a] = paths[u];
                q.push(mp(-dis[a], a));
            }
            else if (dis[a] == dis[u] + b)
                paths[a] += paths[u];
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("qbschool.inp", "r", stdin);
    freopen("qbschool.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    bfs();
    cout << dis[n] << " " << paths[n];
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;

const int maxv = 4e5 + 2, maxe = 2e5 + 2;
const ll INF = 2e18;
int n, m;
vector<ll> dis(maxv, INF);
vector<ii> adj[maxv];

void input()
{
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].pb(mp(w, v));
    }
}

void bfs()
{
    dis[1] = 0;
    priority_queue<ii> q;
    q.push(mp(0, 1));
    while (!q.empty())
    {
        int u = q.top().Y;
        q.pop();
        for (ii a : adj[u])
        {
            int w = a.X, v = a.Y;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                q.push(mp(-dis[v], v));
            }
        }
    }
}

int main()
{
    freopen("dijkstra.inp", "r", stdin);
    freopen("dijkstra.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    bfs();
    if (dis[n] == INF)
        cout << "-1";
    else
        cout << dis[n];
    return 0;
}
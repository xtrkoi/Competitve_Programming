#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

const int maxv = 5e4 + 3, maxe = 1e5 + 3, INF = 1e9;
const ll mod = 11235813;
int n, m;
vb seen(maxv, false);
vector<vi> adj(maxv);
vi dis(maxv, INF);
vector<ll> paths(maxv);

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

void bfs()
{
    dis[1] = 0;
    paths[1] = 1;
    queue<int> q;
    q.push(1);
    seen[1] = true;
    bitset<maxv> seen_2;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        seen_2 &= 0;
        for (int v : adj[u])
        {
            if (!seen[v])
            {
                seen[v] = true;
                seen_2[v] = 1;
                q.push(v);
                dis[v] = dis[u] + 1;
                paths[v] = paths[u];
            }
            else if (dis[v] == dis[u] + 1 && !seen_2[v])
            {
                paths[v] = (paths[v] + paths[u]) % mod;
                seen_2[v] = 1;
            }
        }
    }
}

int main()
{
    freopen("nummin.inp", "r", stdin);
    freopen("nummin.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    bfs();
    for (int i = 1; i <= n; i++)
        cout << paths[i] << " ";
    return 0;
}
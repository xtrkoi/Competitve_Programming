#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

const int maxn = 1e5 + 2, INF = 2e9;
const ll VINF = LONG_LONG_MAX - 2;
int n, m;
struct edge
{
    int u, v, c;
    edge()
    {
        u = v = c = 0;
    }
    edge(int a, int b, int k)
    {
        u = a;
        v = b;
        c = k;
    }
    bool operator<(const edge &rhs)
    {
        return c < rhs.c;
    }
};
vector<edge> edge_list;
vector<vii> adj(maxn);
vii trace(maxn);
vi dis(maxn, INF);
vector<ll> wei(maxn, VINF);

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edge_list.pb(edge(u, v, c));
    }
    sort(edge_list.begin(), edge_list.end());
    for (edge i : edge_list)
    {
        adj[i.u].pb(mp(i.v, i.c));
        adj[i.v].pb(mp(i.u, i.c));
    }
}

void find_path(int i)
{
    stack<int> res;
    while (trace[i].X != 1)
    {
        res.push(trace[i].Y);
        i = trace[i].X;
    }
    res.push(trace[i].Y);
    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }
}

void bfs()
{
    priority_queue<pair<ll, int>> q;
    q.push(mp(0, 1));
    dis[1] = 0;
    wei[1] = 0;
    while (!q.empty())
    {
        int u = q.top().Y;
        q.pop();
        for (ii v : adj[u])
        {
            if (dis[v.X] > dis[u] + 1 || (trace[v.X].Y > v.Y && dis[v.X] == dis[u] + 1))
            {
                trace[v.X] = mp(u, v.Y);
                dis[v.X] = dis[u] + 1;
                wei[v.X] = wei[u] + v.Y;
                q.push(mp(-wei[v.X], v.X));
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("mecung.inp", "r", stdin);
    freopen("mecung.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    bfs();
    cout << dis[n] << "\n";
    find_path(n);
    return 0;
}

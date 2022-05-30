#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxv = 1e5 + 3, maxe = 1e5 + 3;
const ll INF = 4e18;
int n, m, k, s, t;
vector<ii> city;
vector<ll> dis_st(maxv, INF), dis_ed(maxv, INF);
vector<vii> adj(maxv);

void input()
{
    cin >> n >> m >> k >> s >> t;
    int id, c, u, v, w;
    for (int i = 0; i < k; i++)
    {
        cin >> id >> c;
        city.pb(mp(id, c));
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].pb(mp(w, v));
        adj[v].pb(mp(w, u));
    }
}

void bfs(int start, vector<ll> &dis)
{
    dis[start] = 0;
    priority_queue<ii> q;
    q.push(mp(0, start));
    while (!q.empty())
    {
        int u = q.top().Y;
        q.pop();
        for (ii v : adj[u])
        {
            if (dis[v.Y] > dis[u] + v.X)
            {
                dis[v.Y] = dis[u] + v.X;
                q.push(mp(-dis[v.Y], v.Y));
            }
        }
    }
}

void run()
{
    ll res = INF;
    for (ii i : city)
        res = min(res, i.Y + dis_st[i.X] + dis_ed[i.X]);
    cout << res;
}

int main()
{
    freopen("money.inp", "r", stdin);
    freopen("money.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    bfs(s, dis_st);
    bfs(t, dis_ed);
    run();
    return 0;
}
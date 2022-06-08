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

const int maxn = 1e5 + 5, INF = INT_MAX;
int n, m;
vector<vii> adj(maxn);
vi d1(maxn, INF), d2(maxn, INF), res;
vector<bool> seen(maxn, false);

struct edge
{
    int u, v, c;
    edge()
    {
        u = v = c = 0;
    }
    edge(int i, int j, int k)
    {
        u = i;
        v = j;
        c = k;
    }
    bool operator<(const edge &rhs)
    {
        return u < rhs.u || (u == rhs.u && v < rhs.v) || (u == rhs.u && v == rhs.v && c < rhs.c);
    }
};
vector<edge> edge_list;

void input()
{
    cin >> n >> m;
    int u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        if (u > v)
            swap(u, v);
        edge_list.pb(edge(u, v, c));
    }
    sort(edge_list.begin(), edge_list.end());
    edge prev = edge();
    for (edge i : edge_list)
    {
        if (i.u == prev.u && i.v == prev.v)
            continue;
        adj[i.u].pb(mp(i.v, i.c));
        adj[i.v].pb(mp(i.u, i.c));
        prev = i;
    }
}

void bfs(int st, vi &dis)
{
    queue<int> q;
    q.push(st);
    dis[st] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (ii v : adj[u])
        {
            if (dis[v.X] > dis[u] + 1)
            {
                dis[v.X] = dis[u] + 1;
                q.push(v.X);
            }
        }
    }
}

bool shortest(int a)
{
    return d1[a] + d2[a] == d1[n];
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
    bfs(1, d1);
    bfs(n, d2);

    vector<vi> tmp(2);
    int i = 0;
    tmp[i].pb(1);
    for (int k = 1; k <= d1[n]; k++)
    {
        int mn = INF;
        for (int u : tmp[i])
            for (ii v : adj[u])
                if (d1[v.X] == d1[u] + 1 && !seen[v.X] && shortest(v.X))
                    mn = min(mn, v.Y);
        res.pb(mn);
        for (int u : tmp[i])
            for (ii v : adj[u])
                if (d1[v.X] == d1[u] + 1 && !seen[v.X] && shortest(v.X) && v.Y == mn)
                {
                    tmp[1 - i].pb(v.X);
                    seen[v.X] = true;
                }
        tmp[i].clear();
        i = 1 - i;
    }
    cout << d1[n] << "\n";
    for (int j : res)
        cout << j << " ";
    return 0;
}

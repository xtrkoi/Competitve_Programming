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
vi d1(maxn, INF), d2(maxn, INF), res(maxn);

struct edge
{
    int u, v, c;
    bool operator<(const edge &rhs)
    {
        return u < rhs.u || (u == rhs.u && v < rhs.v) || (u == rhs.u && v == rhs.v && c < rhs.c);
    }
};
vector<edge> edge_list;

void input()
{
    cin >> n >> m;
    edge tmp;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp.u >> tmp.v >> tmp.c;
        edge_list.pb(tmp);
    }
    sort(edge_list.begin(), edge_list.end());
    adj[edge_list[0].u].pb(mp(edge_list[0].v, edge_list[0].c));
    adj[edge_list[0].v].pb(mp(edge_list[0].u, edge_list[0].c));
    for (int i = 1; i < m; i++)
        if (edge_list[i].u != edge_list[i - 1].u || edge_list[i].v != edge_list[i - 1].v)
        {
            adj[edge_list[i].u].pb(mp(edge_list[i].v, edge_list[i].c));
            adj[edge_list[i].v].pb(mp(edge_list[i].u, edge_list[i].c));
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
                if (d1[v.X] == d1[u] + 1 && shortest(v.X))
                    mn = min(mn, v.Y);
        res[k] = mn;
        for (int u : tmp[i])
            for (ii v : adj[u])
                if (d1[v.X] == d1[u] + 1 && shortest(v.X) && v.Y == mn)
                    tmp[1 - i].pb(v.X);
        tmp[i].clear();
        i = 1 - i;
    }
    cout << d1[n] << "\n";
    for (int j = 1; j <= d1[n]; j++)
        cout << res[j] << " ";
    return 0;
}

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
typedef vector<bool> vb;

const int maxn = 255, INF = INT_MAX;
int n, m, s, t;
vector<vi> adj(maxn);
vector<vector<vi>> dis(maxn, vector<vi>(maxn, vi(2, INF)));

void input()
{
    cin >> n >> m >> s >> t;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
    }
}
void bfs()
{
    queue<pair<ii, int>> q;
    q.push(mp(mp(s, t), 0));
    dis[s][t][0] = 0;
    while (!q.empty())
    {
        int u = q.front().X.X;
        int v = q.front().X.Y;
        int p = q.front().Y;
        q.pop();

        if (p == 0)
            for (int k : adj[u])
            {
                if (dis[k][v][1 - p] == INF)
                {
                    dis[k][v][1 - p] = dis[u][v][p] + 1;
                    q.push(mp(mp(k, v), 1 - p));
                }
            }
        else
            for (int k : adj[v])
            {
                if (dis[u][k][1 - p] == INF)
                {
                    dis[u][k][1 - p] = dis[u][v][p] + 1;
                    q.push(mp(mp(u, k), 1 - p));
                }
            }
    }
    int res = INF;
    for (int i = 1; i <= n; i++)
        res = min(res, dis[i][i][0]);
    cout << (res == INF ? -1 : res / 2) << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("qbagents.inp", "r", stdin);
    freopen("qbagents.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    bfs();
    return 0;
}

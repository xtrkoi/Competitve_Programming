#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

const int maxn = 505, maxm = 8002, INF = 2e9;
int n, C, P;
vector<vii> adj(maxn);
vector<bool> seen(maxn, false);
vector<vi> dis(maxn, vi(maxn, INF));
vi f, res(maxn, 0);

void input()
{
    cin >> P >> n >> C;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        f.pb(tmp);
    }
    int u, v, w;
    for (int i = 0; i < C; i++)
    {
        cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
}

void bfs(int s)
{
    priority_queue<ii> q;
    q.push(mp(0, s));
    dis[s][s] = 0;
    while (!q.empty())
    {
        int u = q.top().Y;
        q.pop();
        if (seen[u])
            continue;
        seen[u] = true;
        for (ii v : adj[u])
        {
            if (dis[s][v.X] > dis[s][u] + v.Y)
            {
                dis[s][v.X] = dis[s][u] + v.Y;
                q.push(mp(-dis[s][v.X], v.X));
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("bestspot.inp", "r", stdin);
    freopen("bestspot.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();

    for (int i = 1; i <= P; i++)
    {
        bfs(i);
        seen = vector<bool>(maxn, false);
    }

    for (int i = 1; i <= P; i++)
        for (int j : f)
            res[i] += dis[i][j];

    int mn = INF;
    int ans = 0;
    for (int i = 1; i <= P; i++)
        if (res[i] < mn)
        {
            ans = i;
            mn = res[i];
        }

    cout << ans;
    return 0;
}
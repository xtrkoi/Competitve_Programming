#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 1e4 + 2, mod = 1e9 + 7;
int n, m, s;
vi dis(maxn), paths(maxn);
vector<vi> adj(maxn);
vector<bool> seen(maxn, false);

void input()
{
    cin >> n >> m >> s;
    int u, v;
    for (int i = 1; i < m; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
    }
}

void sanitize()
{
    for (vector<vi>::iterator i = adj.begin(); i != adj.end(); i++)
    {
        sort(i->begin(), i->end());
        i->resize(distance(i->begin(), unique(i->begin(), i->end())));
    }
}

void bfs()
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    paths[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!seen[v])
            {
                seen[v] = true;
                q.push(v);
                dis[v] = dis[u] + 1;
                paths[v] = paths[u];
            }
            else if (dis[v] == dis[u] + 1)
                paths[v] = (paths[v] + paths[u]) % mod;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("stable.inp", "r", stdin);
    freopen("stable.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    sanitize();
    bfs();
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (i != s && paths[i] > 1)
            cnt++;
    cout << cnt;
    return 0;
}
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

const int maxv = 1e4 + 2, maxe = 1e5 + 2;
int n, m, s, t;
vector<bool> seen(maxv);
vector<vi> adj(maxv);
vi path, pos(maxv, -1);

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

void find_path()
{
    vi trace(n + 2, -1);
    queue<int> q;
    q.push(s);
    trace[s] = s;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (trace[v] < 0)
            {
                trace[v] = u;
                q.push(v);
            }
        }
    }

    int u = t;
    while (u != s)
    {
        path.pb(u);
        u = trace[u];
    }
    path.pb(s);
    reverse(path.begin(), path.end());
}

int bfs(int st)
{
    queue<int> q;
    q.push(st);
    seen[st] = true;
    int mx = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!seen[v] && pos[v] < 0)
            {
                seen[v] = true;
                q.push(v);
            }
            else
                mx = max(mx, pos[v]);
        }
    }
    return mx;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("stnode.inp", "r", stdin);
    freopen("stnode.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    find_path();

    for (int i = 0; i < (int)sz(path); i++)
        pos[path[i]] = i + 1;

    int mx = -1, res = 0;
    for (int u : path)
    {
        if (u != s && u != t && mx <= pos[u])
            res++;
        mx = max(mx, bfs(u));
    }
    cout << res;
    return 0;
}
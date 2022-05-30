#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;

const int maxv = 1e5 + 2, maxe = 1e6 + 2;
int n, m, s, t, trace[maxv];
vector<bool> seen(maxv, false);
vector<ii> edge;
vector<vector<int>> adj(maxv);

void input()
{
    cin >> n >> m >> s >> t;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        edge.pb(mp(u, v));
    }

    sort(edge.begin(), edge.end());

    for (int i = 0; i < m; i++)
        adj[edge[i].X].pb(edge[i].Y);
}

void output()
{
    cout << s << " ";
    vector<int> print_path;
    while (t != s)
    {
        print_path.pb(t);
        t = trace[t];
    }
    vector<int>::iterator j = print_path.end();
    while (j != print_path.begin())
    {
        j--;
        cout << *j << " ";
    }
}

void bfs(int st)
{
    int cnt = 0;
    queue<int> q;
    q.push(st);
    seen[st] = true;
    trace[st] = st;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < sz(adj[u]); v++)
            if (!seen[adj[u][v]])
            {
                seen[adj[u][v]] = true;
                q.push(adj[u][v]);
                trace[adj[u][v]] = u;
                if (adj[u][v] == t)
                {
                    output();
                    exit(0);
                }
            }
        cnt++;
    }
}

int main()
{
    freopen("bfs.inp", "r", stdin);
    freopen("bfs.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    bfs(s);
    return 0;
}
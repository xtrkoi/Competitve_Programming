#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

const int maxv = 1005;
int t, n, m, cnt;
vb seen(maxv);
vvi adj(maxv);
stack<int> s;

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

void topo_sort(int u)
{
    seen[u] = true;
    for (int v : adj[u])
        if (!seen[v])
            topo_sort(v);
    s.push(u);
}

void dfs(int u)
{
    static int stop = false;
    seen[u] = true;
    bool check = false;
    for (int v : adj[u])
        if (!seen[v])
        {
            dfs(v);
            if (stop)
                return;
            if (!check)
                check = true;
        }
    if (!check)
        stop = true;
}

void run(int testcase)
{
    cnt = 0;
    seen = vb(maxv, false);
    adj = vvi(maxv);

    input();

    for (int i = 1; i <= n; i++)
        if (!seen[i])
            topo_sort(i);

    seen = vb(maxv, false);

    while (!s.empty())
    {
        if (!seen[s.top()])
        {
            dfs(s.top());
            cnt++;
        }
        s.pop();
    }
    cout << "Case " << testcase << ": " << cnt << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("ninjaioi.inp", "r", stdin);
    freopen("ninjaioi.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 1; i <= t; i++)
        run(i);
    return 0;
}

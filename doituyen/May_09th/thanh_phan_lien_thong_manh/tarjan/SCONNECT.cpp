#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef vector<int> vi;

const int maxv = 1e5 + 2;
int n, m;
vi adj[maxv], disc(maxv, -1), low(maxv, 0);
vector<bool> seen(maxv, false);
stack<int> s;

void input()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
    }
}

void dfs(int u)
{
    static int time = 0;
    low[u] = disc[u] = ++time;
    seen[u] = true;
    s.push(u);
    for (int v : adj[u])
    {
        if (disc[v] < 0)
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (seen[v])
            low[u] = min(low[u], disc[v]);
    }

    if (low[u] == disc[u])
    {
        while (s.top() != u)
        {
            cout << s.top() << " ";
            seen[s.top()] = false;
            s.pop();
        }
        cout << s.top() << "\n";
        seen[s.top()] = false;
        s.pop();
    }
}

int main()
{
    freopen("sconnect.inp", "r", stdin);
    freopen("sconnect.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for (int i = 1; i <= n; i++)
        if (disc[i] < 0)
            dfs(i);
    return 0;
}
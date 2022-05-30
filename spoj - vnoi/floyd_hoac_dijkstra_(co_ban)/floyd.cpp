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
typedef vector<ii> vii;

const int maxn = 105, INF = 2e9;
int n, m, k;
vector<vi> dis(maxn, vi(maxn, INF)), trace(maxn, vi(maxn));
vector<vii> adj(maxn);

void input()
{
    cin >> n >> m >> k;
    int u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        adj[u].pb(mp(v, c));
        adj[v].pb(mp(u, c));
    }
}

void find_sp(int s)
{
    dis[s][s] = 0;
    priority_queue<ii> q;
    q.push(mp(0, s));
    trace[s][s] = 0;
    while (!q.empty())
    {
        int u = q.top().Y;
        q.pop();
        for (ii v : adj[u])
        {
            if (dis[s][v.X] > dis[s][u] + v.Y)
            {
                dis[s][v.X] = dis[s][u] + v.Y;
                trace[s][v.X] = u;
                q.push(mp(-dis[s][v.X], v.X));
            }
        }
    }
}

void find_path(int i, int j)
{
    stack<int> res;
    while (j != i)
    {
        res.push(j);
        j = trace[i][j];
    }
    res.push(i);
    cout << res.size() << " ";
    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }
    cout << "\n";
}

void ans_query()
{
    int t, u, v;
    while (k--)
    {
        cin >> t >> u >> v;
        if (t == 0)
            cout << abs(dis[u][v] - dis[u][u]) << "\n";
        else
            find_path(u, v);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("floyd.inp", "r", stdin);
    freopen("floyd.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for (int i = 1; i <= n; i++)
        find_sp(i);
    ans_query();
    return 0;
}
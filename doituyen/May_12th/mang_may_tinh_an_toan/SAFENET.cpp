#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 1e5 + 3, maxm = 2e5 + 3, INF = 1e9;
int n, m, prev_cnt, cnt = 0;
vi disc(maxn, 0), low(maxn), tmp, res;
vector<vi> adj(maxn);
stack<ii> s;

void input()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void dfs(int u, int p = -1)
{
    disc[u] = ++cnt;
    low[u] = INF;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (disc[v] > 0)
            low[u] = min(low[u], disc[v]);
        else
        {
            s.push(mp(u, v));
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= disc[u])
            {
                tmp.pb(v);
                ii out = s.top();
                while (out != mp(u, v))
                {
                    s.pop();
                    tmp.pb(out.Y);
                    out = s.top();
                }
                tmp.pb(out.X);
                s.pop();

                if (sz(res) < sz(tmp))
                    res = tmp;
                tmp.clear();
            }
        }
    }
}

int main()
{
    freopen("safenet.inp", "r", stdin);
    freopen("safenet.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for (int i = 1; i <= n; i++)
        if (!disc[i])
        {
            prev_cnt = cnt;
            dfs(i);
            if (cnt = prev_cnt + 1)
                tmp.pb(i);
            if (sz(res) < sz(tmp))
                res = tmp;
            tmp.clear();
        }

    cout << sz(res) << "\n";
    for (int i : res)
        cout << i << " ";
    return 0;
}
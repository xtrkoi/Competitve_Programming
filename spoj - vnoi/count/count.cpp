#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 2e5 + 5;
int n;
vi colors(maxn), color_size(maxn, 1);
vector<vi> adj(maxn);
vector<set<int>> uni_col(maxn);

void input()
{
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> colors[i];
}

void dfs(int u, int p = -1)
{
    uni_col[u].insert(colors[u]);
    for (int v : adj[u])
        if (v != p)
        {
            dfs(v, u);
            uni_col[u].insert(uni_col[v].begin(), uni_col[v].end());
        }
    color_size[u] = uni_col[u].size();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("count.inp", "r", stdin);
    freopen("count.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << color_size[i] << " ";
    return 0;
}
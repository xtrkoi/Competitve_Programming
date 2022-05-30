#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef long long ll;

const int maxv = 1e5 + 3, maxe = 1e6 + 3;
int n, m;
vector<bool> seen(maxv, false);
vector<vector<int> > adj(maxv);
priority_queue<int, vector<int>, greater<int> > connected;

void input()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void dfs(int u)
{
    seen[u] = true;
    connected.push(u);
    for (int v : adj[u])
        if (!seen[v])
            dfs(v);
}

int main()
{
    freopen("connect.inp", "r", stdin);
    freopen("connect.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for (int i = 1; i <= n; i++)
        if (!seen[i])
        {
            dfs(i);
            while (!connected.empty())
            {
                cout << connected.top() << " ";
                connected.pop();
            }
            cout << "\n";
        }
    return 0;
}
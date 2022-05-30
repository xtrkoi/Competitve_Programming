#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(A) A.size()

const int max_vertex = 100;
bool seen[max_vertex];
vector<vector<int>> adj(max_vertex);

void visit(int u)
{
    cout << u << "\n";
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    seen[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        visit(u);
        q.pop();
        for (int i = 0; i < sz(adj[u]); i++)
        {
            if (!seen[adj[u][i]])
            {
                seen[adj[u][i]] = true;
                q.push(adj[u][i]);
            }
        }
    }
}

void add_edge(int u, int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

int main()
{
    freopen("demo.inp", "r", stdin);
    freopen("demo.out", "w", stdout);
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(1, 4);
    add_edge(1, 5);
    add_edge(2, 3);
    bfs(0);
    return 0;
}

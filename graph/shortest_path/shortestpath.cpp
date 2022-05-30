#include <bits/stdc++.h>
using namespace std;

const int MAX_VERTEX = 100;
const int INF = numeric_limits<int>::max();
bool seen[MAX_VERTEX];
vector<vector<int>> adj(MAX_VERTEX);
vector<int> dis(MAX_VERTEX, INF);

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    seen[s] = true;
    dis[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (!seen[v])
            {
                // recompute distance to v
                dis[v] = dis[u] + 1;
                seen[v] = true;
                q.push(v);
            }
        }
    }
}

void add_edge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void shortest_dis()
{
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(1, 4);
    add_edge(4, 5);
    bfs(0);
    for (int v = 0; v < 6; ++v)
    {
        cout << "shortest dis from 0->" << v << ": " << dis[v] << endl;
    }
}

int main()
{
    freopen("shortestpath.inp", "r", stdin);
    freopen("shortestpath.out", "w", stdout);
    shortest_dis();
    return 0;
}
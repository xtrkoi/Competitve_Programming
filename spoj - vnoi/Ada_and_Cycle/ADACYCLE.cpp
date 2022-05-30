#include <bits/stdc++.h>
#define pb push_back
#define sz(A) A.size()
using namespace std;

const int maxv = 2002;
vector<vector<int>> adj(maxv);
bool visited[maxv];
int n, f[maxv];

void input() 
{
    scanf("%d", &n);
    int tmp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &tmp);
            if (tmp)
                adj[i].pb(j);
        }
}

void bfs(int x)
{
    queue<int> q;
    visited[x] = true;
    q.push(x);
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (int i = 0; i < sz(adj[k]); i++)
        {
            if (!visited[adj[k][i]])
            {
                q.push(adj[k][i]);
                visited[adj[k][i]] = true;
                f[adj[k][i]] = f[k] + 1;
            }
            if (visited[adj[k][i]] && adj[k][i] == x)
            {
                printf("%d\n", f[k]);
                return;
            }
        }
    }
    printf("NO WAY\n");
}

void run()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            visited[j] = false;
            f[j] = 1;
        }
        bfs(i);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("adacycle.inp", "r", stdin);
    freopen("adacycle.out", "w", stdout);
#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    input();
    run();
    return 0;
}
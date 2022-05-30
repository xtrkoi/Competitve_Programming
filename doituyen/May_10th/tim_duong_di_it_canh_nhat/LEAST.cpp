#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef vector<int> vi;

const int maxv = 5e4 + 2;
int n, m, cnt_st, cnt_fi;
vi adj[maxv + 2], st, fi, steps(maxv + 2, 0);
vector<bool> seen(maxv, false);

void input()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
    }
    cin >> cnt_st;
    for (int i = 0; i < cnt_st; i++)
    {
        cin >> u;
        st.pb(u);
    }
    cin >> cnt_fi;
    for (int i = 0; i < cnt_fi; i++)
    {
        cin >> v;
        fi.pb(v);
    }
}

void bfs(int s, int t)
{
    queue<int> q;
    q.push(s);
    seen[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!seen[v])
            {
                seen[v] = true;
                steps[v] = steps[u] + 1;
                if (v == t)
                {
                    cout << steps[v] - 2;
                    exit(0);
                }
                q.push(v);
            }
        }
    }
}

void run()
{
    for (int u : st)
        adj[n + 1].pb(u);
    for (int v : fi)
        adj[v].pb(n + 2);
    bfs(n + 1, n + 2);
}

int main()
{
    freopen("least.inp", "r", stdin);
    freopen("least.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
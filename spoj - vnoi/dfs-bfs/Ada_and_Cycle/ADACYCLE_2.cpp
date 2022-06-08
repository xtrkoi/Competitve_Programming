#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;

const int maxn = 2002;

struct node
{
    vi adj;
    vi rev_adj;
} g[maxn];
int n, scc_cnt = 0, component_id[maxn];
vi scc[maxn], steps(maxn), res(maxn);
vector<bool> seen(maxn, false);
stack<int> s;

void input()
{
    cin >> n;
    int tmp;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
        {
            cin >> tmp;
            if (tmp)
            {
                g[u].adj.pb(v);
                g[v].rev_adj.pb(u);
            }
        }
}

void dfs_1(int x)
{
    seen[x] = true;
    for (int v : g[x].adj)
        if (!seen[v])
            dfs_1(v);
    s.push(x);
}

void dfs_2(int x)
{
    component_id[x] = scc_cnt;
    scc[scc_cnt].pb(x);
    seen[x] = true;
    for (int v : g[x].rev_adj)
        if (!seen[v])
            dfs_2(v);
}

void kosaraju()
{
    for (int i = 1; i <= n; i++)
        if (!seen[i])
            dfs_1(i);

    for (int i = 1; i <= n; i++)
        seen[i] = false;

    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        if (!seen[v])
        {
            scc_cnt++;
            dfs_2(v);
        }
    }
}

void bfs(int id, int u)
{
    queue<int> q;
    q.push(u);
    steps[u] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto w : scc[id])
        {
            if (w != u && !seen[w])
            {
                steps[w] = steps[v] + 1;
                seen[w] = true;
                q.push(w);
            }
            else if (w == u && !seen[w])
                seen[w] = true;
            else if (w == u && seen[w])
            {
                res[w] = steps[v] + 1;
                return;
            }
        }
    }
}

void run()
{
    for (int i = 1; i <= scc_cnt; i++)
    {
        if (scc[i].size() == 1)
            res[scc[i][0]] = -1;
        for (int j : scc[i])
        {
            bool check = false;
            for (int v : g[j].adj)
                if (v == j)
                {
                    res[j] = 1;
                    check = true;
                    break;
                }
            if (check)
                continue;
            for (int h = 1; h <= n; h++)
                seen[h] = false;
            bfs(i, j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (res[i] < 0)
            cout << "NO WAY\n";
        else
            cout << res[i] << "\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("adacycle.inp", "r", stdin);
    freopen("adacycle2.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    kosaraju();
    run();
    // cout << scc_cnt << "\n";
    // for (int i = 1; i <= scc_cnt; i++)
    // {
    //     for (int v : scc[i])
    //         cout << v << " ";
    //     cout << "\n";
    // }
    return 0;
}
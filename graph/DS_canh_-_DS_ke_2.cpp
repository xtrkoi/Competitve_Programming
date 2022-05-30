// chuyen tu danh sach canh sang danh sach ke cua do thi co huong
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

const int maxv = 1000;
vector<ii> e;
int adj[maxv * 2], head[maxv + 2], link[maxv + 1];
int n = 5, m = 7;

void add_edge(int u, int v)
{
    e.pb(mp(u, v));
}

void conv_edge_adjlist()
{
    for (int i = 1; i <= n; i++)
        head[i] = 0;
    for (int i = 0; i < m; i++)
        head[e[i].X]++;
    for (int i = 2; i <= n; i++)
        head[i] += head[i - 1];
    for (int i = m - 1; i >= 0; i--)
    {
        adj[head[e[i].X]] = e[i].Y;
        head[e[i].X]--;
    }
    head[n + 1] = m;
}

int main()
{
    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(2, 3);
    add_edge(2, 4);
    add_edge(2, 5);
    add_edge(3, 5);
    add_edge(4, 5);
    conv_edge_adjlist();
    for (int i = 1; i <= m; i++)
        cout << adj[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n + 1; i++)
        cout << head[i] << " ";
    return 0;
}
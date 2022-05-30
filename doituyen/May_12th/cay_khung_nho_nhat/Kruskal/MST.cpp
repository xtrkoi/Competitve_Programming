#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef pair<int, int> ii;
typedef long long ll;

struct edge
{
    int u, v;
    ll w;
    edge()
    {
        u = v = w = 0;
    }

    edge(int inp_u, int inp_v, ll inp_w)
    {
        u = inp_u;
        v = inp_v;
        w = inp_w;
    }

    bool operator<(const edge &rhs)
    {
        return w < rhs.w;
    }
};

const int maxn = 1e5 + 5;
int n, m;
long long res = 0;
vector<edge> edge_list;

int link[maxn], size[maxn];

void input()
{
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edge_list.pb(edge(a, b, c));
    }
}

void UFS() // Union-Find Structure
{
    for (int i = 1; i <= n; i++)
    {
        link[i] = i;
        size[i] = 1;
    }
}

int find(int x)
{
    if (x == link[x])
        return x;
    return link[x] = find(link[x]);
}

bool same(int a, int b)
{
    return find(a) == find(b);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (size[a] < size[b])
        swap(a, b);
    size[a] += size[b];
    link[b] = a;
}

void find_mst()
{
    sort(edge_list.begin(), edge_list.end());
    for (int i = 0; i < m; i++)
        if (!same(edge_list[i].u, edge_list[i].v))
        {
            unite(edge_list[i].u, edge_list[i].v);
            res += edge_list[i].w;
        }
}

int main()
{
    freopen("mst.inp", "r", stdin);
    freopen("mst.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    UFS();
    find_mst();
    for (int i = 1; i <= n; i++)
        if (size[i] == n)
        {
            cout << res;
            return 0;
        }
    cout << "DISCONNECTED";
    return 0;
}

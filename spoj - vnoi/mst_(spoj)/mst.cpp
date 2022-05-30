#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

struct edge
{
    int u, v, w;
    edge()
    {
        u = v = w = 0;
    }
    edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
    bool operator<(const edge &rhs)
    {
        return w < rhs.w;
    }
};
vector<edge> edge_list;
const int maxn = 1e4 + 2;
int n, m;
vi tag(maxn), vol(maxn, 1);

void input()
{
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edge_list.pb(edge(a, b, c));
    }
    sort(edge_list.begin(), edge_list.end());
}

int find(int x)
{
    if (x == tag[x])
        return x;
    return tag[x] = find(tag[x]);
}

bool same(int a, int b)
{
    return find(a) == find(b);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (vol[a] < vol[b])
        swap(a, b);
    tag[b] = a;
    vol[a] += vol[b];
}

void run()
{
    ll res = 0;
    for (int i = 1; i <= n; i++)
        tag[i] = i;
    for (edge a : edge_list)
    {
        if (!same(a.u, a.v))
        {
            unite(a.u, a.v);
            res += a.w;
            if (vol[find(a.u)] == n || vol[find(a.v)] == n)
                break;
        }
    }
    cout << res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("mst.inp", "r", stdin);
    freopen("mst.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
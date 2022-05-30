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

const int maxn = 1002;
int n, m;
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
    for (int i = 1; i <= n; i++)
        tag[i] = i;
    int res = 0;
    for (edge a : edge_list)
    {
        if (!same(a.u, a.v))
        {
            unite(a.u, a.v);
            res = max(res, a.w);
            if (vol[find(a.u)] == n || vol[find(a.v)] == n)
                break;
        }
    }
    cout << res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("nkcity.inp", "r", stdin);
    freopen("nkcity.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
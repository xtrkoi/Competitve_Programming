#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxv = 1e6 + 3, maxe = 5e6 + 3;
int n, m;
vector<ii> bridge;
vi link(maxv), size(maxv);

void input()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        bridge.pb(mp(u, v));
    }
}

void djs()
{
    for (int i = 0; i <= n; i++)
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
    link[b] = a;
    size[a] += size[b];
}

void run()
{
    for (int i = 0; i < m; i++)
        if (!same(bridge[i].X, bridge[i].Y))
        {
            unite(bridge[i].X, bridge[i].Y);
            if (size[find(bridge[i].X)] == n || size[find(bridge[i].Y)] == n)
            {
                cout << i + 1;
                return;
            }
        }
}

int main()
{
    freopen("cau.inp", "r", stdin);
    freopen("cau.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    djs();
    run();
    return 0;
}

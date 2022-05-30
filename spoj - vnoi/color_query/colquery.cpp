#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 1e5 + 5;
int n, q;
vi color(maxn), tag(maxn), vol(maxn);
vector<vi> color_set(maxn);

void input()
{
    cin >> n >> q;
    int col;
    for (int i = 1; i <= n; i++)
    {
        cin >> col;
        color[i] = col;
        // color_set[col].pb(i);
    }
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
    if (vol[a] > vol[b])
        swap(a, b);
    tag[b] = a;
    vol[a] += vol[b];
    for (int i : color_set[b])
        color_set[a].pb(i);
}

void run()
{
    int s, u, v;
    cin >> s >> u >> v;
    if (s == 1)
    {
        if (!same(u, v))
            unite(u, v);
    }
    else if (s == 2)
    {
        int cnt = 0;
        /* if (!color_set[v].empty())
            for (int i : color_set[v])
                if (same(u, i))
                    cnt++; */
        for (int i : color_set[find(u)])
            if (color[i] == v)
                cnt++;
        cout << cnt << "\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("colquery.inp", "r", stdin);
    freopen("colquery.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for (int i = 1; i <= n; i++)
    {
        tag[i] = i;
        vol[i] = 1;
        color_set[i].pb(i);
    }
    while (q--)
        run();
    return 0;
}
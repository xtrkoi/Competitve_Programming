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
vi color(maxn), tag(maxn), rank(maxn, 1);
multiset<int> s[maxn];

void input()
{
    cin >> n >> q;
    int col;
    for (int i = 1; i <= n; i++)
    {
        cin >> col;
        color[i] = col;
        s[i].insert(col);
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
    if (rank[a] > rank[b])
        swap(a, b);
    tag[b] = a;
    rank[a] += rank[b];
    s[a].insert(s[b].begin(), s[b].end());
}

void run()
{
    int q, u, v, c;
    cin >> q;
    if (q == 1)
    {
        cin >> u >> v;
        if (!same(u, v))
            unite(u, v);
    }
    else if (q == 2)
    {
        cin >> u >> c;
        cout << s[find(u)].count(c) << "\n";
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
        tag[i] = i;
    while (q--)
        run();
    return 0;
}
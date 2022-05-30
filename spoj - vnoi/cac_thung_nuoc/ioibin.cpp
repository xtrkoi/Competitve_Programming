#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

const int maxn = 1e4 + 5;

int p;
vector<int> tag, vol(maxn, 1);

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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("ioibin.inp", "r", stdin);
    freopen("ioibin.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < maxn; i++)
        tag.pb(i);
    cin >> p;
    int x, y, z;
    while (p--)
    {
        cin >> x >> y >> z;
        if (z == 1 && !same(x, y))
            unite(x, y);
        else if (z == 2)
        {
            if (same(x, y))
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
    return 0;
}
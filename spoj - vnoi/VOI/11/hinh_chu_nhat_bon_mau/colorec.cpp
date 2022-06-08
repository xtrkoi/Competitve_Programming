#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;

struct pt
{
    int x, y, c;
    pt()
    {
        x = y = c = 0;
    }
    pt(int nx, int ny, int nc)
    {
        x = nx;
        y = ny;
        c = nc;
    }
};

const int maxn = 1e5 + 2, INF = 2e9;
int n;
vector<pt> arr;

void input()
{
    cin >> n;
    int u, v, w;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v >> w;
        arr.pb(pt(u, v, w));
    }
}

bool check(const pt &a, const pt &b, const pt &c, const pt &d)
{
    set<int> s;
    s.insert(a.c);
    s.insert(b.c);
    s.insert(c.c);
    s.insert(d.c);
    if (sz(s) != 4)
        return false;
    set<int> dx, dy;
    dx.insert(a.x);
    dx.insert(b.x);
    dx.insert(c.x);
    dx.insert(d.x);
    dy.insert(a.y);
    dy.insert(b.y);
    dy.insert(c.y);
    dy.insert(d.y);
    return (dx.size() == 2 && dy.size() == 2 ? true : false);
}

void run()
{
    ll cnt = 0;
    for (int i = 0; i < n - 3; i++)
        for (int j = i + 1; j < n - 2; j++)
            for (int k = j + 1; k < n - 1; k++)
                for (int p = k + 1; p < n; p++)
                    if (check(arr[i], arr[j], arr[k], arr[p]))
                        cnt++;
    cout << cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("colorec.inp", "r", stdin);
    freopen("colorec.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
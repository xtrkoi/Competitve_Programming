#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 5e3 + 2;
const ll INF = 2e18;

struct pt
{
    ll x, y;
    pt()
    {
        x = y = 0;
    }
    pt(ll a, ll b)
    {
        x = a;
        y = b;
    }
};

int n, m;
vector<pt> post, meteor;

void input()
{
    cin >> n;
    int u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        post.pb(pt(u, v));
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        meteor.pb(pt(u, v));
    }
}

ll cp(const pt &a, const pt &b, const pt &c)
{
    return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}

int CCW(const pt &a, const pt &b, const pt &c)
{
    ll tmp = cp(a, b, c);
    if (tmp > 0)
        return 1;
    if (tmp < 0)
        return -1;
    return 0;
}

bool inside(pt s)
{
    for (int i = 0; i < n; i++)
        if (CCW(post[i], post[(i + 1) % n], s) <= 0)
            return false;
    return true;
}

void run()
{
    for (pt r : meteor)
    {
        if (inside(r))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    freopen("meterain.inp", "r", stdin);
    freopen("meterain.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
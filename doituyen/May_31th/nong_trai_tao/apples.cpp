#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int maxn = 1e6 + 2;
const ll INF = 2e18;

struct pt
{
    ll x, y, id;
    pt()
    {
        x = y = id = 0;
    }
    pt(ll a, ll b, ll c)
    {
        x = a;
        y = b;
        id = c;
    }
};

int n;
vector<pt> arr;
pt pivot;

void input()
{
    cin >> n;
    int u, v, d = 0;
    pivot = pt(INF, INF, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> u >> v;
        arr.pb(pt(u, v, i));
        if (v < pivot.y || (v == pivot.y && u < pivot.x))
        {
            pivot = pt(u, v, i);
            d = i;
        }
    }
    arr.erase(arr.begin() + d - 1);
}

inline ll cp(const pt &a, const pt &b, const pt &c)
{
    return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}

inline int CCW(const pt &a, const pt &b, const pt &c)
{
    ll tmp = cp(a, b, c);
    if (tmp > 0)
        return 1;
    if (tmp < 0)
        return -1;
    return 0;
}

bool comp(const pt &a, const pt &b)
{
    ll tmp = CCW(a, b, pivot);
    return tmp > 0;
}

void run()
{
    sort(arr.begin(), arr.end(), comp);
    cout << pivot.id << " " << arr[(int)((n - 2) / 2)].id;
}

int main()
{
    freopen("apples.inp", "r", stdin);
    freopen("apples.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
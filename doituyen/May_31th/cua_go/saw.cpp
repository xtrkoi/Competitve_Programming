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
typedef long double ld;

struct pt
{
    ll x, y;
    pt()
    {
        x = y = 0;
    }
    pt(ll a, ll b)
    {
        x = abs(a);
        y = b;
    }
    bool operator<(const pt &rhs)
    {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
};

inline ll cp(const pt &a, const pt &b, const pt &c)
{
    return (a.y - c.y) * b.x + (c.y - b.y) * a.x + (b.y - a.y) * c.x;
}

inline ld area(const pt &a, const pt &b)
{
    ld t1 = (a.x * b.y - a.y * b.x) * (a.x * b.y - a.y * b.x);
    ld t2 = (a.x - b.x) * (b.y - a.y);
    return t1 / t2;
}

const int maxn = 1e5 + 2;
int k, n, r;
vector<pt> arr, s(maxn);

void input()
{
    cin >> n;
    ll a, b;
    n++;
    while (n--)
    {
        cin >> a >> b;
        arr.pb(pt(a, b));
    }
}

int main()
{
    freopen("saw.inp", "r", stdin);
    freopen("saw.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    while (k--)
        input();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < sz(arr); i++)
    {
        while (r > 1 && cp(s[r - 1], s[r], arr[i]) >= 0)
            r--;
        s[++r] = arr[i];
        if (arr[i].y == 0)
            break;
    }
    ld res = 0;
    for (int i = 1; i < r; i++)
        res = max(res, area(s[i], s[i + 1]));
    cout << setprecision(6) << fixed << res;
    return 0;
}
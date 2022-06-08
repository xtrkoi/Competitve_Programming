#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 3e3 + 2;

struct pt
{
    ll x, y;
};

int n;
ll r, r2, res;
vector<pt> a(maxn), s(maxn), s2(maxn);

ll cp(const pt &a, const pt &b, const pt &c)
{
    return (a.y - c.y) * b.x + (c.y - b.y) * a.x + (b.y - a.y) * c.x;
}

bool comp(const pt &a, const pt &b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int main()
{
    freopen("triland.inp", "r", stdin);
    freopen("triland.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a.begin() + 1, a.begin() + n + 1, comp);
    for (int i = 1; i <= n; i++)
    {
        while (r > 1 && cp(s[r - 1], s[r], a[i]) <= 0)
            r--;
        while (r2 > 1 && cp(s2[r2 - 1], s2[r2], a[i]) >= 0)
            r2--;
        s[++r] = s2[++r2] = a[i];
    }
    while (r2--)
        s[++r] = s2[r2];
    r -= 2;
    for (int i = 1; i < r; i++)
    {
        int k = i + 2;
        for (int j = i + 1; j < r; j++)
        {
            while (k < r && cp(s[i], s[j], s[k + 1]) >= cp(s[i], s[j], s[k]))
                k++;
            res = max(res, cp(s[i], s[j], s[k]));
        }
    }
    cout << res / 2 << (res % 2 != 0 ? ".5" : ".0");
    return 0;
}
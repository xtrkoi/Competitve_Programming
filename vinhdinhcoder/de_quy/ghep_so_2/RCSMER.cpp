#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = LONG_LONG_MAX - 2;
ll a, b, res;

ll rev(ll x)
{
    if (x == 0)
        return 0;
    ll ans = 0;
    while (x > 0)
    {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

void run(ll x, ll y, bool fmin, ll tmp = 0)
{
    if (x == 0)
    {
        if (y == 0)
        {
            if (fmin)
                res = min(res, tmp);
            else
                res = max(res, tmp);
            return;
        }
        run(x, y / 10, fmin, tmp * 10 + y % 10);
    }
    else if (y == 0)
    {
        if (x == 0)
        {
            if (fmin)
                tmp = min(tmp, res);
            else
                tmp = max(tmp, res);
            return;
        }
        run(x / 10, y, fmin, tmp * 10 + x % 10);
    }
    else if ((x % 10 < y % 10 && fmin) || (x % 10 > y % 10 && !fmin))
        run(x / 10, y, fmin, tmp * 10 + x % 10);

    else if ((x % 10 > y % 10 && fmin) || (x % 10 < y % 10 && !fmin))
        run(x, y / 10, fmin, tmp * 10 + y % 10);

    else
    {
        run(x / 10, y, fmin, tmp * 10 + x % 10);
        run(x, y / 10, fmin, tmp * 10 + y % 10);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("rcsmer.inp", "r", stdin);
    freopen("rcsmer.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    a = rev(a);
    b = rev(b);

    res = INF;
    run(a, b, true);
    cout << res << "\n";

    res = -INF;
    run(a, b, false);
    cout << res << "\n";

    return 0;
}
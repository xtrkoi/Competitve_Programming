#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, res = 0;

void run(ll x, ll y, bool fmin)
{
    if (x == 0)
    {
        if (y == 0)
            return;
        res = res * 10 + y % 10;
        run(x, y / 10, fmin);
    }
    else if (y == 0)
    {
        if (x == 0)
            return;
        res = res * 10 + x % 10;
        run(x / 10, y, fmin);
    }
    else if ((x % 10 < y % 10 && fmin) || (x % 10 > y % 10 && !fmin))
    {
        res = res * 10 + x % 10;
        run(x / 10, y, fmin);
    }
    else
    {
        res = res * 10 + y % 10;
        run(x, y / 10, fmin);
    }
}

ll rev(ll x)
{
    if (x == 0)
        return 0;
    ll res = 0;
    while (x > 0)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
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
    run(a, b, 1);
    cout << res << "\n";
    res = 0;
    run(a, b, 0);
    cout << res;
    return 0;
}
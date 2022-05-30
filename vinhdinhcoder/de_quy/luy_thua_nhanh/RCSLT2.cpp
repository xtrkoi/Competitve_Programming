#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
ll x, n;

ll expo(ll b, ll e)
{
    if (e == 0)
        return 1;
    if (e == 1)
        return b;
    if (e % 2 == 0)
    {
        ll a = expo(b, e / 2) % mod;
        return (a * a) % mod;
    }
    else
    {
        ll a = expo(b, (e - 1) / 2) % mod;
        return ((b * a) % mod * a) % mod;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("rcslt2.inp", "r", stdin);
    freopen("rcslt2.out", "w", stdout);
#endif // !ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> n;
    cout << expo(x, n);
    return 0;
}
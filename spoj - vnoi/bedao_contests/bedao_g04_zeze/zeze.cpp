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

const ll mod = 1e9 + 7;
ll n, m, cnt = 0;
ll cnt0(ll x)
{
    if (x == 0)
        return x;
    while (x % 10 == 0)
    {
        cnt++;
        x /= 10;
    }
    return x;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("zeze.inp", "r", stdin);
    freopen("zeze.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m;
    ll prev;
    cin >> prev;
    cnt0(prev);
    for (int i = 1; i < m; i++)
    {
        cin >> n;
        n = cnt0(n);
        prev *= n;
        prev = cnt0(prev);
        prev %= mod;
    }
    cout << cnt;
    return 0;
}
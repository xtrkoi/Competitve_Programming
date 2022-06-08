#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll f[101];
int n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("tongs.inp", "r", stdin);
    freopen("tongs.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = f[i - 1] * i;
    ld res = 0;
    for (int i = 1; i <= n; i++)
        res += (ld)1 / f[i];
    cout << setprecision(10) << fixed << res;
    return 0;
}
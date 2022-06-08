#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

ld n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("tonge.inp", "r", stdin);
    freopen("tonge.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ld k = 1;
    ld e = 0;
    while (e <= n)
    {
        e += 1 / (k * k);
        k++;
    }
    cout << setprecision(9) << fixed << e;
    return 0;
}
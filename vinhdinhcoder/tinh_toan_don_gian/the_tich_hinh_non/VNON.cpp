#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld pi = 3.14159265358983414828;
ld h, r;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("vnon.inp", "r", stdin);
    freopen("vnon.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> r;
    ld res = (h * pi * r * r) / 3;
    cout << setprecision(8) << fixed << res;
    return 0;
}
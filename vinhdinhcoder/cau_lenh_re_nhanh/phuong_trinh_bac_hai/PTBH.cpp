#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

ld a, b, c;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("ptbh.inp", "r", stdin);
    freopen("ptbh.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    cout << setprecision(2) << fixed;
    ld delta = b * b - 4 * a * c;
    if (delta < 0)
        cout << "VO NGHIEM";
    else if (delta == 0)
        cout << "PT CO NGHIEM KEP\nX = " << -b / (2 * a);
    else
        cout << "PT CO HAI NGHIEM\nX1 = " << (-b + sqrt(delta)) / (2 * a) << "\nX2 = " << (-b - sqrt(delta)) / (2 * a);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const long double pi = (long double)3.1415926535899;

long double r;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("shtron.inp", "r", stdin);
    freopen("shtron.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r;
    cout << setprecision(9) << fixed;
    long double a = 97687294905826;
    long double b = 5576274;
    long double c = a / (b * b);
    long long res = pi * r * r;
    cout << res;
    // cout << setprecision(0) << fixed << res;
    // cout << setprecision(31) << fixed << c;
    return 0;
}
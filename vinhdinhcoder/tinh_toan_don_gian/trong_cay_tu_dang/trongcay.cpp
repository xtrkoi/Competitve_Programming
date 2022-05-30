#include <iostream>
using namespace std;
long long x, y, z;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("trongcay.inp", "r", stdin);
    freopen("trongcay.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y >> z;
    x *= 1000;
    long long res = (x - z) / (y + z);
    cout << res;
    return 0;
}
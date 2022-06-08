#include <bits/stdc++.h>
using namespace std;

int a, b;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("tongchanab.inp", "r", stdin);
    freopen("tongchanab.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    long long res = 0;
    for (int i = a; i <= b; i++)
        if (i % 2 == 0)
            res += i;
    cout << res;
    return 0;
}
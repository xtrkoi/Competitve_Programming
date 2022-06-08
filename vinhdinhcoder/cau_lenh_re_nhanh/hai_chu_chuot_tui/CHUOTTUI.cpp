#include <bits/stdc++.h>
using namespace std;

double x1, x2, v1, v2;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("chuottui.inp", "r", stdin);
    freopen("chuottui.out", "w", stdout);
#endif
    cin >> x1 >> v1 >> x2 >> v2;
    if ((x1 - x2) / (v2 - v1) == trunc((x1 - x2) / (v2 - v1)) && (x1 - x2) / (v2 - v1) > 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
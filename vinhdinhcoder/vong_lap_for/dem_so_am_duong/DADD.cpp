#include <bits/stdc++.h>
using namespace std;

int n, res1, res2;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("dadd.inp", "r", stdin);
    freopen("dadd.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int tmp;
    while (n--)
    {
        cin >> tmp;
        if (tmp > 0)
            res1++;
        if (tmp < 0)
            res2++;
    }
    cout << "SO DUONG: " << res1 << "\nSO AM: " << res2;
    return 0;
}
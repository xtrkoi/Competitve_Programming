#include <bits/stdc++.h>
using namespace std;

int n, c;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("desert.inp", "r", stdin);
    freopen("desert.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    int tmp;
    while (n--)
    {
        cin >> tmp;
        c -= tmp;
        if (c <= 0)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("keine.inp", "r", stdin);
    freopen("keine.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        cout << s << "\n";
        n *= 2;
        while (n--)
            cin >> s;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int t;
ll n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("maxmod.inp", "r", stdin);
    freopen("maxmod.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << n / 2 + 1 << "\n";
    }
    return 0;
}
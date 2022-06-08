#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("number.inp", "r", stdin);
    freopen("number.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cout << n * 18;
    return 0;
}
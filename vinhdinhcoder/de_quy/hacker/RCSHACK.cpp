#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int t;
ll n;

bool check(ll x)
{
    if (x == 1)
        return true;
    if (x % 10 != 0)
        return false;
    return check(x / 10) || check(x / 20);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("rcshack.inp", "r", stdin);
    freopen("rcshack.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (check(n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
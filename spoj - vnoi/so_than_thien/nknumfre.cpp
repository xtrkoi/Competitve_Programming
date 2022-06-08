#include <bits/stdc++.h>
using namespace std;

int a, b, res = 0;

bool gcd(int x, int y)
{
    while (x % y != 0)
    {
        int tmp = y;
        y = x % y;
        x = tmp;
    }
    return (y == 1 ? true : false);
}

int rev_int(int x)
{
    if (x == 0)
        return x;
    int ans = 0;
    while (x > 0)
    {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("nknumfre.inp", "r", stdin);
    freopen("nknumfre.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        if (gcd(i, rev_int(i)))
            res++;
    cout << res;
    return 0;
}
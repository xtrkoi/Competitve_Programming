#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], b[200005];
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
}
int ucln(int x, int y)
{
    int r = x % y;
    while (r != 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}
int run(int x)
{
    int res = a[1] + x;
    for (int i = 2; i <= n; i++)
    {
        res = ucln(res, a[i] + x);
        if (res == 1)
            return 1;
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("gcd.inp", "r", stdin);
    freopen("gcd.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for (int i = 1; i <= m; i++)
        cout << run(b[i]) << " ";
    return 0;
}

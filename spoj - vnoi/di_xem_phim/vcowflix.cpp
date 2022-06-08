#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int n, w, a[maxn], f[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("vcowflix.inp", "r", stdin);
    freopen("vcowflix.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> w >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = w; j >= a[i]; j--)
            f[j] = (f[j] || f[j - a[i]]);
    }
    for (int i = w; i >= 0; i--)
        if (f[i])
        {
            cout << i;
            return 0;
        }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;

const int maxn = 1002;
int n, a[maxn];
ll f[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("nkjump.inp", "r", stdin);
    freopen("nkjump.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    for (int k = 3; k <= n; k++)
    {
        int i = 1;
        int j = k - 1;
        while (i < j)
        {
            if (a[i] + a[j] == a[k])
            {
                f[k] = max(f[k], max(f[i], f[j]) + 1);
                i++, j--;
            }
            if (a[i] + a[j] > a[k])
                j--;
            if (a[i] + a[j] < a[k])
                i++;
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i] + 1);
    cout << res;
    return 0;
}
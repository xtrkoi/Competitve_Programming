#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 3e5 + 2;
int n;
ll len;
vector<ll> x(maxn), t(maxn);

void input()
{
    cin >> n >> len;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> t[i];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("train.inp", "r", stdin);
    freopen("train.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        ll tmp = t[i] / (len * 2);
        res += tmp;
        if (t[i] - tmp * len / 2 > 0)
            res++;
    }
    cout << res * 2 * len;
    return 0;
}
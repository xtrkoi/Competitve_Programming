#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, arr[200002];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("lis.inp", "r", stdin);
    freopen("lis.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    arr[0] = -1;
    int len = 0;
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] != arr[i - 1])
            len++;
        res += len;
    }
    cout << res;
    return 0;
}
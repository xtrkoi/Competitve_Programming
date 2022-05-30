#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int n, t;
ll cn, cv, ct;
vector<ll> arr, sq;

void input()
{
    cin >> n >> t;
    ll tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.pb(tmp);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
        sq.pb(arr[i] * arr[i]);
}

void run()
{
    cn = cv = ct = 0;
    int a, b, mx;
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
        {
            a = lower_bound(sq.begin() + j, sq.end(), sq[i] + sq[j]) - sq.begin();
            b = upper_bound(sq.begin() + j, sq.end(), sq[i] + sq[j]) - sq.begin();
            mx = lower_bound(arr.begin() + j, arr.end(), arr[i] + arr[j]) - arr.begin();
            cv += b - a;
            cn += a - j - 1;
            ct += mx - b + 1;
        }
    if (t == 1)
        cout << cn;
    if (t == 2)
        cout << cv;
    if (t == 3)
        cout << ct;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("tri.inp", "r", stdin);
    freopen("tri.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}

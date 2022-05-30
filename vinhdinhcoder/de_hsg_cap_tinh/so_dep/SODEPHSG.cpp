#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;

int n;
ll m, res = 0;
vector<ll> arr;

void input()
{
    cin >> n >> m;
    ll tmp; 
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.pb(tmp);
    }
    sort(arr.begin(), arr.end());
}

void run()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++) 
    }
    cout << res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("sodephsg.inp", "r", stdin);
    freopen("sodephsg.out", "w", stdout);
#endif // !ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 4e18;
int n, arr[1000002];
ll ss[1000002], dp[1000002];
vector<bool> prime(1000002, true);

void sieve()
{
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= 1000001; i++)
        if (prime[i])
            for (int j = i * i; j <= 1000001; j += i)
                prime[j] = false;
}

void set_subfix_sum()
{
    ss[1] = arr[1];
    for (int i = 2; i <= n; i++)
        ss[i] = ss[i - 1] + arr[i];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("easy_task.inp", "r", stdin);
    freopen("easy_task.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    sieve();
    set_subfix_sum();

    dp[2] = arr[2];
    int prev_prime = 2;

    for (int i = 3; i <= n; i++)
        if (prime[i])
        {
            dp[i] = max((ll)arr[i], dp[prev_prime] + ss[i] - ss[prev_prime]);
            prev_prime = i;
        }

    ll res = -INF;
    for (int i = 1; i <= n; i++)
        if (prime[i])
            res = max(res, dp[i]);
    cout << res;
    return 0;
}
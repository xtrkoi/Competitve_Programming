#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
typedef pair<ll, int> plli;

vector<ll> arr, set_sum[2];
int n;
ll s;

void input()
{
    cin >> n >> s;
    ll tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.pb(tmp);
    }
}

void dfs(int i, int top, int p)
{
    static ll tmp = 0;
    for (int c = 0; c <= 1; c++)
    {
        tmp += arr[i] * c;

        if (i + 1 == top)
            set_sum[p].pb(tmp);
        else
            dfs(i + 1, top, p);

        tmp -= arr[i] * c;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("btktrau1.inp", "r", stdin);
    freopen("btktrau1.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    dfs(0, min(n, 20), 0);
    sort(set_sum[0].begin(), set_sum[0].end());
    set_sum[0].resize(distance(set_sum[0].begin(), unique(set_sum[0].begin(), set_sum[0].end())));

    if (n > 20)
    {
        dfs(20, n, 1);
        sort(set_sum[1].begin(), set_sum[1].end());
        set_sum[1].resize(distance(set_sum[1].begin(), unique(set_sum[1].begin(), set_sum[1].end())));
    }

    if (n <= 20 && s <= set_sum[0].back())
        cout << (binary_search(set_sum[0].begin(), set_sum[0].end(), s) ? "YES" : "NO");
    else if (n > 20 && s <= set_sum[1].back())
    {
        for (ll i : set_sum[1])
            if (binary_search(set_sum[0].begin(), set_sum[0].end(), s - i))
            {
                cout << "YES";
                return 0;
            }
        cout << "NO";
    }
    else
        cout << "NO";
    return 0;
}
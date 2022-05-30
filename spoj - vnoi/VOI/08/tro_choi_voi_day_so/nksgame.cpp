#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int INF = 2e9 + 5;
int n;
vector<int> a, b;

void input()
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.pb(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        b.pb(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

void run()
{
    int res = INF;
    for (int i = 0; i < n; i++)
    {
        int j = lower_bound(b.begin(), b.end(), -a[i]) - b.begin();
        if (j >= n)
            j--;
        res = min(res, min(abs(a[i] + b[j]), (j == 0 ? INF : abs(a[i] + b[j - 1]))));
    }
    cout << res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("nksgame.inp", "r", stdin);
    freopen("nksgame.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
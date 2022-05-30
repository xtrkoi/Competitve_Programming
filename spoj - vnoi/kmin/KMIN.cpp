#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef pair<int, int> ii;
typedef vector<ii> vii;

int m, n, k;
vector<int> a, b;

void input()
{
    cin >> m >> n >> k;
    int tmp;
    for (int i = 1; i <= m; i++)
    {
        cin >> tmp;
        a.pb(tmp);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        b.pb(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

void run()
{
    int i = 0, j = 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("kmin.inp", "r", stdin);
    freopen("kmin.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}

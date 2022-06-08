#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 5e4 + 2;
int t, n;
vi a(maxn), b(maxn), d(maxn);

bool run()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    int k = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < b[i])
            return false;
        d[i] = a[i] - b[i];
        if (b[i] != 0)
            k = max(k, d[i]);
    }

    if (k < 0)
        return true;
    for (int i = 1; i <= n; i++)
        if (d[i] > k || (b[i] != 0 && d[i] != k))
            return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("ad.inp", "r", stdin);
    freopen("ad.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
        cout << (run() ? "YES\n" : "NO\n");
    return 0;
}
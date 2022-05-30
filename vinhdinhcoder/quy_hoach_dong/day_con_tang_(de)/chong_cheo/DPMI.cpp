#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define sz(A) (int)A.size()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof(a))

const int mod = 1e8, lim = 3e3 + 7;
int n, f[lim];
ii arr[lim];
ll c[lim];

void input()
{
    scanf("%d", &n);
    if (n < 0)
        return;
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &arr[i].X, &arr[i].Y);
}

bool comp(const ii &a, const ii &b)
{
    if (a.Y != b.Y)
        return a.Y < b.Y;
    return a.X < b.X;
}

void run()
{
    sort(arr + 1, arr + n + 1, comp);
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        c[i] = 1;
        for (int j = 1; j < i; j++)
            if (arr[i].X >= arr[j].Y)
            {
                c[i] += c[j];
                c[i] %= mod;
                f[i] = max(f[i], f[j] + 1);
            }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += c[i];
        res %= mod;
    }
    printf("%08lld\n", res);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("dpmi.inp", "r", stdin);
    freopen("dpmi.out", "w", stdout);
#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    while (true)
    {
        input();
        if (n < 0)
            break;
        run();
    }
    return 0;
}
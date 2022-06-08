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

const int maxn = 10;
int n;
vi arr(maxn), f(maxn), bit(maxn);

inline int cb(int x)
{
    return x * (x - 1) / 2;
}

void initBIT()
{
    for (int i = 1; i <= n; i++)
    {
        bit[i] += cb(f[i]);
        if (i + (i & -i) <= n)
            bit[i + (i & -i)] += bit[i];
    }
}

int getSum(int p)
{
    int ans = 0;
    while (p > 0)
    {
        ans += bit[p];
        p -= (p & -p);
    }
    return ans;
}

void update(int p, int v)
{
    while (p <= n)
    {
        bit[p] += v;
        p += (p & -p);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("balls.inp", "r", stdin);
    freopen("balls.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        f[arr[i]]++;
    }

    initBIT();
    for (int i = 1; i <= n; i++)
    {
        update(arr[i], -(cb(f[arr[i]]) - cb(f[arr[i]] - 1)));
        cout << getSum(n) << "\n";
        update(arr[i], cb(f[arr[i]]) - cb(f[arr[i]] - 1));
    }
    return 0;
}
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

const int base = 26, maxn = 5e4 + 4;
const ll sh = 1e9 + 3, sh2 = sh * sh;

ll h[maxn], pw[maxn], ph[maxn], f[maxn];
ll res, n, k;
bool chk;
string a;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("dtksub.inp", "r", stdin);
    freopen("dtksub.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> a;
    if (k == 1)
    {
        cout << n;
        return 0;
    }
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = (base * pw[i - 1]) % sh;
        ph[i] = (base * ph[i - 1] + (a[i - 1] - 'a')) % sh;
    }

    int lt = 1, rt = n;
    while (lt <= rt)
    {
        int mid = (lt + rt) >> 1;
        for (int i = mid; i <= n; i++)
            h[i] = (ph[i] - pw[mid] * ph[i - mid] + sh2) % sh;
        sort(h + mid, h + n);
        f[mid] = 1, chk = false;
        for (int i = mid + 1; i <= n; i++)
        {
            f[i] = (h[i] == h[i - 1] ? f[i - 1] + 1 : 1);
            if (f[i] >= k)
            {
                chk = true;
                break;
            }
        }
        if (chk)
        {
            lt = mid + 1;
            res = mid;
        }
        else
            rt = mid - 1;
    }
    cout << res;
    return 0;
}

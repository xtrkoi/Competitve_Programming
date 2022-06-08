#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 1e5 + 2;
int n;
vector<bool> s(maxn, true);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("exponential.inp", "r", stdin);
    freopen("exponential.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if (n < 4)
    {
        cout << 1;
        return 0;
    }
    int res = 0;
    s[0] = s[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (s[i])
            for (int j = i * i; j <= n; j *= i)
            {
                s[j] = false;
                res = max(res, j);
            }
    cout << res;
    return 0;
}
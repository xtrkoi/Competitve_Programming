#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int maxn = 1e5 + 2;
string a, b;
int dp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("c11str2.inp", "r", stdin);
    freopen("c11str2.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    dp[0] = 0;
    for (int i = 0; i < sz(a); i++)
        if (a[i] == b[dp[i - 1]])
            dp[i] = dp[i - 1] + 1;
    cout << a;
    for (int i = dp[sz(a) - 1]; i < sz(b); i++)
        cout << b[i];
    return 0;
}
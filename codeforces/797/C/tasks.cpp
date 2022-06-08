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

const int maxn = 2e5 + 2;
int t, n;
vi s(maxn), f(maxn);

void run()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> f[i];
    for (int i = 1; i <= n; i++)
        cout << f[i] - max(s[i], f[i - 1]) << " ";
    cout << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("tasks.inp", "r", stdin);
    freopen("tasks.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
        run();
    return 0;
}
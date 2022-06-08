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

int t, n, d;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("pedestal.inp", "r", stdin);
    freopen("pedestal.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        d = (n % 3 == 0 ? 0 : 3);
        int a = (n + d) / 3;
        int b = (n + d) / 3 + 1;
        int c = n - (a + b);
        if (c == 0)
        {
            a--;
            c++;
        }
        cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}
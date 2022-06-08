#include <bits/stdc++.h>
using namespace std;

#define sz(A) (int)A.size()

typedef long long ll;

string s;
long long res = 0;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("countpair.inp", "r", stdin);
    freopen("countpair.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    ll cnt_1 = 0;
    for (int i = 0; i < sz(s); i++)
    {
        if (s[i] == '1')
            cnt_1++;
        if (s[i] == '2')
            res += cnt_1;
    }
    cout << res;
    return 0;
}
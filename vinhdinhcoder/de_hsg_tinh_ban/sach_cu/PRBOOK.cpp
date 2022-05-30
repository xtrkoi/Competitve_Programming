#include <bits/stdc++.h>
using namespace std;

#define sz(A) A.size()
typedef long long ll;

string s;
ll cnt[10];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("prbook.inp", "r", stdin);
    freopen("prbook.out", "w", stdout);
#endif // !ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int chk = 0;
    for (int i = 0; i < (int)sz(s); i++)
    {
        int j = s[i] - '0';
        cnt[j]++;
        chk += j;
        chk %= 3;
    }
    if (chk % 3 != 0 || !cnt[0])
        cout << "-1\n";
    else
        for (int i = 9; i >= 0; i--)
            while (cnt[i]--)
                cout << i;
    return 0;
}
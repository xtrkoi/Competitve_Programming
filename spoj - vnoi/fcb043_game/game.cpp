#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

int n;
string s;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    int cnt_8 = 0;
    bool chk = false;
    for (int i = n - 1; i >= 0; i--)
        if (s[i] == '8')
        {
            cnt_8++;
            if (i < n - 11)
                chk = true;
        }
    if (chk && cnt_8 >= (n - 11) / 2 + 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
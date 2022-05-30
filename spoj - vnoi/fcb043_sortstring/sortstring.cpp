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

int cnt[125];
string s;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("sortstring.inp", "r", stdin);
    freopen("sortstring.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for (int i = 0; i < (int)sz(s); i++)
        cnt[(int)s[i]]++;
    for (int i = 'Z'; i >= 'A'; i--)
        while (cnt[i]--)
            cout << (char)i;
    for (int i = 'z'; i >= 'a'; i--)
        while (cnt[i]--)
            cout << (char)i;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define sz(A) (int)A.size()

int n;
string s;

inline bool lc(char x)
{
    return 'a' <= x && x <= 'z';
}

inline bool uc(char x)
{
    return 'A' <= x && x <= 'Z';
}

void run()
{
    getline(cin, s);
    for (int i = 0; i < sz(s); i++)
    {
        if ((i == 0 || s[i - 1] == ' ') && lc(s[i]))
            s[i] -= ('a' - 'A');
        else if (i > 0 && (lc(s[i - 1]) || uc(s[i - 1])) && uc(s[i]))
            s[i] += ('a' - 'A');
    }
    cout << s << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("name.inp", "r", stdin);
    freopen("name.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    getline(cin, s);
    while (n--)
        run();
    return 0;
}
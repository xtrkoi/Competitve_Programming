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

string a, b;
vi res, dp;

void input()
{
    cin >> a >> b;
    dp = vi(sz(b), 0);
}

void create()
{
    int i = 0;
    for (int j = 1; j < (int)sz(b); j++)
    {
        if (b[i] == b[j])
        {
            dp[j] = i + 1;
            i++;
        }
        else
            i = 0;
    }
}

void run()
{
    int m = sz(a);
    int n = sz(b);
    int i = 0, j = 0;
    while (i < m - n + 1)
    {
        while (j < n && a[i + j] == b[j])
            j++;
        if (j == n)
            res.pb(i + 1);
        if (j == 0)
            i++;
        else
        {
            i = i + j - dp[j - 1];
            j = dp[j - 1];
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("substr.inp", "r", stdin);
    freopen("substr.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    create();
    run();
    for (int i : res)
        cout << i << " ";
    return 0;
}
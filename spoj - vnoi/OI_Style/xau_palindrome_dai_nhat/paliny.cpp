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

const int maxn = 5e4 + 2;
int n, i, j, res;
string s;

void tryy(int st, int fi)
{
    int dd;
    if (st == fi)
    {
        dd = 1;
        st--;
        fi++;
    }
    else
        dd = 0;

    for (;;)
    {
        if (st < 0 || fi >= n)
            break;
        if (s[st] == s[fi])
        {
            dd += 2;
            st--;
            fi++;
        }
        else
            break;
    }
    res = max(res, dd);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("paliny.inp", "r", stdin);
    freopen("paliny.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    i = n / 2;
    j = n / 2 + 1;
    res = 1;
    while (i >= res / 2 && j < n - res / 2)
    {
        if (i >= res / 2)
        {
            tryy(i, i);
            tryy(i, i + 1);
        }
        if (j + 1 < n - res / 2)
        {
            tryy(j, j);
            tryy(j, j + 1);
        }
        i--;
        j++;
    }
    cout << res;
    return 0;
}
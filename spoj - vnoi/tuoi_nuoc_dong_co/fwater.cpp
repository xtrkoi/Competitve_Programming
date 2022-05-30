#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int maxn = 302, INF = 2e9;
int n;
vector<ll> c(maxn, INF);
vector<vi> p(maxn, vi(maxn, 0));
vector<bool> seen(maxn, false);

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[0][i];
        p[i][0] = p[0][i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> p[i][j];
            p[i][i] = INF;
        }
}

int find_path()
{
    ll res = 0;
    c[0] = 0;
    for (int k = 0; k <= n; k++)
    {
        int u = 0, mn = INF;
        for (int i = 0; i <= n; i++)
        {
            if (!seen[i] && c[i] < mn)
            {
                mn = c[i];
                u = i;
            }
        }
        res += c[u];
        seen[u] = true;
        for (int j = 0; j <= n; j++)
            if (!seen[j] && c[j] > p[u][j])
                c[j] = p[u][j];
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("fwater.inp", "r", stdin);
    freopen("fwater.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout << find_path();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sz(A) A.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 2e9, maxn = 102;
int n, m;
vector<vi> adj(maxn, vi(maxn)), dis(maxn, vi(maxn, INF));
vi arr;
vector<bool> seen(maxn, false);

void input()
{
    cin >> n >> m;
    int tmp;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        arr.pb(tmp);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> adj[i][j];
}

void find_path()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (adj[i][k] + adj[k][j] < adj[i][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
}

void run()
{
    ll res = 0;
    for (int i = 0; i < m - 1; i++)
        res += adj[arr[i]][arr[i + 1]];
    cout << res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("vdanger.inp", "r", stdin);
    freopen("vdanger.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    find_path();
    run();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;

const int maxn = 115, INF = 1e9;
int n, mn, mx;
vector<vi> arr(maxn, vi(maxn));
vector<vb> seen(maxn, vb(maxn));
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
}

void border()
{
    for (int i = 0; i <= n + 1; i++)
        seen[i][0] = seen[i][n + 1] = true;
    for (int i = 0; i <= n + 1; i++)
        seen[0][i] = seen[n + 1][i] = true;
}

bool dfs(int u, int v)
{
    seen[u][v] = true;
    if (u == n && v == n)
        return true;
    for (int k = 0; k < 4; k++)
    {
        int x = u + dx[k], y = v + dy[k];
        if (!seen[x][y] && mn <= arr[x][y] && arr[x][y] <= mx)
            if (dfs(x, y))
                return true;
    }
    return false;
}

void run()
{
    int res = INF;
    for (mn = 0; mn <= arr[1][1]; mn++)
    {
        int low = 0, high = maxn;
        while (low < high)
        {
            int mid = (low + high) >> 1;
            mx = mn + mid;
            seen = vector<vb>(maxn, vb(maxn, false));
            border();
            bool reach = dfs(1, 1);
            if (reach)
            {
                high = mid;
                res = min(res, mx - mn);
            }
            else
                low = mid + 1;
        }
    }
    cout << res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("mtwalk.inp", "r", stdin);
    freopen("mtwalk.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
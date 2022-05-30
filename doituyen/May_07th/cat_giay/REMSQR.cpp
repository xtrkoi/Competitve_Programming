#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;

const int maxn = 102;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int m, n;
bool seen[maxn][maxn];

void input()
{
    cin >> m >> n;
    for (int i = 0; i <= m + 1; i++)
        seen[i][0] = seen[i][n + 1] = true;
    for (int j = 0; j <= n + 1; j++)
        seen[0][j] = seen[m + 1][j] = true;

    string s;
    for (int i = 1; i <= m; i++)
    {
        cin >> s;
        for (int j = 1; j <= n; j++)
        {
            if (s[j - 1] == '#')
                seen[i][j] = false;
            else
                seen[i][j] = true;
        }
    }
}

void dfs(int x, int y)
{
    seen[x][y] = true;
    for (int k = 0; k < 4; k++)
        if (!seen[x + dx[k]][y + dy[k]])
            dfs(x + dx[k], y + dy[k]);
}

int main()
{
    freopen("remsqr.inp", "r", stdin);
    freopen("remsqr.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    int cnt = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (!seen[i][j])
            {
                cnt++;
                dfs(i, j);
            }
    cout << cnt;
    return 0;
}
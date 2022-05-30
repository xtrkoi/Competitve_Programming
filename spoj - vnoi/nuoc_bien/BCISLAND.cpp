#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 102;

bool seen[maxn][maxn];
int test = 0, n, m, area[maxn][maxn], peak;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void set_border()
{
    peak = 0;
    for (int j = 0; j <= m + 1; j++)
        seen[0][j] = seen[n + 1][j] = true;

    for (int i = 0; i <= n + 1; i++)
        seen[i][0] = seen[i][m + 1] = true;
}

void reset_seen()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            seen[i][j] = false;
}

void input()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> area[i][j];
            peak = max(peak, area[i][j]);
        }
    // cout << peak << "\n";
}

void fill_ocean(int x, int y, int level)
{
    seen[x][y] = true;
    queue<ii> q;
    q.push(mp(x, y));
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
            if (!seen[u.X + dx[k]][u.Y + dy[k]] && area[u.X + dx[k]][u.Y + dy[k]] <= level)
            {
                seen[u.X + dx[k]][u.Y + dy[k]] = true;
                q.push(mp(u.X + dx[k], u.Y + dy[k]));
            }
    }
}

void find_ocean(int level)
{
    for (int j = 1; j <= m; j++)
    {
        if (!seen[1][j] && area[1][j] <= level)
            fill_ocean(1, j, level);
        if (!seen[n][j] && area[n][j] <= level)
            fill_ocean(n, j, level);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!seen[i][1] && area[i][1] <= level)
            fill_ocean(i, 1, level);
        if (!seen[i][m] && area[i][m] <= level)
            fill_ocean(i, m, level);
    }
}

bool split_island()
{
    bool check = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!seen[i][j])
            {
                if (check)
                    return false;

                check = true;
                seen[i][j] = true;
                queue<ii> q;
                q.push(mp(i, j));
                while (!q.empty())
                {
                    ii u = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                        if (!seen[u.X + dx[k]][u.Y + dy[k]])
                        {
                            seen[u.X + dx[k]][u.Y + dy[k]] = true;
                            q.push(mp(u.X + dx[k], u.Y + dy[k]));
                        }
                }
            }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("bcisland.inp", "r", stdin);
    freopen("bcisland.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            return 0;
        test++;
        set_border();
        input();
        for (i = 1; i <= peak; i++)
        {
            reset_seen();
            find_ocean(i);
            if (!split_island())
            {
                cout << "Case " << test << ": Island splits when ocean rises " << i << " feet.\n";
                break;
            }
        }
        if (i > peak)
            cout << "Case " << test << ": Island never splits.\n";
    }
}

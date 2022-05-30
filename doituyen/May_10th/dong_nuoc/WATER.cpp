#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 103;
int m, n, area[maxn][maxn], res = 0, peak = 0;
bool seen[maxn][maxn];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> area[i][j];
            peak = max(peak, area[i][j]);
        }
}

void define_boundary()
{
    for (int i = 0; i <= m + 1; i++)
        seen[i][0] = seen[i][n + 1] = true;
    for (int j = 0; j <= n + 1; j++)
        seen[0][j] = seen[m + 1][j] = true;
}

void reset_seen()
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            seen[i][j] = false;
}

void remove_outer(int x, int y, int level)
{
    queue<ii> q;
    q.push(mp(x, y));
    seen[x][y] = true;
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
            if (!seen[u.X + dx[k]][u.Y + dy[k]] && level > area[u.X + dx[k]][u.Y + dy[k]])
            {
                seen[u.X + dx[k]][u.Y + dy[k]] = true;
                q.push(mp(u.X + dx[k], u.Y + dy[k]));
            }
    }
}

int bfs(int x, int y, int level)
{
    queue<ii> q;
    int cnt = 1;
    q.push(mp(x, y));
    seen[x][y] = true;
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
            if (!seen[u.X + dx[k]][u.Y + dy[k]] && level > area[u.X + dx[k]][u.Y + dy[k]])
            {
                seen[u.X + dx[k]][u.Y + dy[k]] = true;
                cnt++;
                q.push(mp(u.X + dx[k], u.Y + dy[k]));
            }
    }
    return cnt;
}

void run()
{
    for (int h = 1; h <= peak; h++)
    {
        reset_seen();
        for (int i = 1; i <= m; i++)
        {
            if (!seen[i][1] && h > area[i][1])
                remove_outer(i, 1, h);
            if (!seen[i][n] && h > area[i][n])
                remove_outer(i, n, h);
        }
        for (int j = 0; j <= n + 1; j++)
        {
            if (!seen[1][j] && h > area[1][j])
                remove_outer(1, j, h);
            if (!seen[m][j] && h > area[m][j])
                remove_outer(m, j, h);
        }
        int tmp_cnt = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (!seen[i][j] && h > area[i][j])
                    tmp_cnt += bfs(i, j, h);
        res += tmp_cnt;
    }
    cout << res;
}

int main()
{
    freopen("water.inp", "r", stdin);
    freopen("water.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    define_boundary();
    run();
    return 0;
}
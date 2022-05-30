#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;

const int maxn = 707;
int n, m, cnt = 0;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
vi qu(10002);
vector<vi> field(maxn, vi(maxn, 0));
vector<vb> seen(maxn, vb(maxn, false));

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> field[i][j];
}

void border()
{
    for (int i = 0; i <= n; i++)
        field[i][0] = field[i][m + 1] = -1;
    for (int j = 0; j <= m; j++)
        field[0][j] = field[n + 1][j] = -1;
}

int hill(int x, int y)
{
    int res = 1;
    seen[x][y] = true;
    int h = field[x][y];
    int bot = 0, top = 2;
    qu[0] = x;
    qu[1] = y;
    while (bot != top)
    {
        int i = qu[bot++], j = qu[bot++];
        for (int k = 0; k < 8; k++)
        {
            int vx = i + dx[k], vy = j + dy[k];
            if (field[vx][vy] > h)
                res = 0;
            else if (field[vx][vy] == h && !seen[vx][vy])
            {
                seen[vx][vy] = true;
                qu[top++] = vx;
                qu[top++] = vy;
            }
        }
    }
    return res;
}

void run()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!seen[i][j] && field[i][j] != 0)
                cnt += hill(i, j);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("nkguard.inp", "r", stdin);
    freopen("nkguard.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    border();
    run();
    cout << cnt;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 1e3 + 2;
// steps la mang luu do dai duong di, res luu dap an cua bai
int m, n, steps[maxn][maxn], res = 0;
bool labyrinth[maxn][maxn], laby_copy[maxn][maxn]; // mang 2 chieu luu me cung va ban sao de chay lan 2
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
ii des; // luu lai điem xa nhat

void input()
{
    cin >> m >> n;
    string s;
    for (int i = 1; i <= m; i++)
    {
        cin >> s;
        for (int j = 1; j <= n; j++)
        {
            if (s[j - 1] == '#')
            {
                labyrinth[i][j] = 1;
                laby_copy[i][j] = 1;
            }
            else
            {
                labyrinth[i][j] = 0;
                laby_copy[i][j] = 0;
            }
        }
    }
}

void define_boundary()
{
    for (int i = 0; i <= m + 1; i++)
        labyrinth[i][0] = labyrinth[i][n + 1] = 1;
    for (int j = 0; j <= n + 1; j++)
        labyrinth[0][j] = labyrinth[m + 1][j] = 1;
}

void bfs(int x, int y)
{
    queue<ii> q;
    q.push(mp(x, y));
    labyrinth[x][y] = 1;
    steps[x][y] = 0;
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
            if (!labyrinth[u.X + dx[k]][u.Y + dy[k]])
            {
                labyrinth[u.X + dx[k]][u.Y + dy[k]] = 1;
                steps[u.X + dx[k]][u.Y + dy[k]] = steps[u.X][u.Y] + 1;
                if (res < steps[u.X + dx[k]][u.Y + dy[k]])
                {
                    des = mp(u.X + dx[k], u.Y + dy[k]);
                    res = steps[u.X + dx[k]][u.Y + dy[k]];
                }
                q.push(mp(u.X + dx[k], u.Y + dy[k]));
            }
    }
}

void run()
{
    bool check = false;
    for (int i = 1; i <= m; i++)
    {
        if (check)
            break;
        for (int j = 1; j <= n; j++)
            if (!labyrinth[i][j])
            {
                bfs(i, j);
                check = true;
                break;
            }
    }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            labyrinth[i][j] = laby_copy[i][j];

    bfs(des.X, des.Y);
    cout << res;
}

int main()
{
    freopen("labyr.inp", "r", stdin);
    freopen("labyr.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    define_boundary();
    run();
    return 0;
}
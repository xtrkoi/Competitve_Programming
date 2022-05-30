#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 256;
int r, c, arr[maxn][maxn], t_cuu = 0, t_soi = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input()
{
    cin >> r >> c;
    string s;
    for (int i = 1; i <= r; i++)
    {
        cin >> s;
        for (int j = 1; j <= c; j++)
        {
            if (s[j - 1] == '.')
                arr[i][j] = 0;
            else if (s[j - 1] == '#')
                arr[i][j] = 1;
            else if (s[j - 1] == 'o')
                arr[i][j] = 2;
            else
                arr[i][j] = 3;
        }
    }
}

void fill_outer(int x, int y)
{
    queue<ii> q;
    q.push(mp(x, y));

    if (arr[x][y] == 2)
        t_cuu++;
    if (arr[x][y] == 3)
        t_soi++;

    arr[x][y] = 1;
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
            if (arr[u.X + dx[k]][u.Y + dy[k]] != 1)
            {
                if (arr[u.X + dx[k]][u.Y + dy[k]] == 2)
                    t_cuu++;
                if (arr[u.X + dx[k]][u.Y + dy[k]] == 3)
                    t_soi++;

                arr[u.X + dx[k]][u.Y + dy[k]] = 1;
                q.push(mp(u.X + dx[k], u.Y + dy[k]));
            }
    }
}

void outer()
{
    for (int i = 0; i <= r + 1; i++)
        arr[i][0] = arr[i][c + 1] = 1;
    for (int j = 0; j <= c + 1; j++)
        arr[0][j] = arr[r + 1][j] = 1;

    for (int i = 1; i <= r; i++)
    {
        if (arr[i][1] != 1)
            fill_outer(i, 1);
        if (arr[i][c] != 1)
            fill_outer(i, c);
    }

    for (int j = 1; j <= c; j++)
    {
        if (arr[1][j] != 1)
            fill_outer(1, j);
        if (arr[r][j] != 1)
            fill_outer(r, j);
    }
}

void bfs(int x, int y)
{
    int cnt_cuu = 0, cnt_soi = 0;
    queue<ii> q;
    q.push(mp(x, y));
    if (arr[x][y] == 2)
        cnt_cuu++;
    if (arr[x][y] == 3)
        cnt_soi++;
    arr[x][y] = 0;
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
            if (arr[u.X + dx[k]][u.Y + dy[k]] != 1)
            {
                if (arr[u.X + dx[k]][u.Y + dy[k]] == 2)
                    cnt_cuu++;
                if (arr[u.X + dx[k]][u.Y + dy[k]] == 3)
                    cnt_soi++;

                arr[u.X + dx[k]][u.Y + dy[k]] = 1;
                q.push(mp(u.X + dx[k], u.Y + dy[k]));
            }
    }

    if (cnt_cuu > cnt_soi)
        t_cuu += cnt_cuu;
    else
        t_soi += cnt_soi;
}

void run()
{
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (arr[i][j] != 1)
                bfs(i, j);
    cout << t_cuu << " " << t_soi;
}

int main()
{
    freopen("soicuu.inp", "r", stdin);
    freopen("soicuu.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    outer();
    run();
    return 0;
}
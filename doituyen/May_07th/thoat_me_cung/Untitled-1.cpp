#include <bits/stdc++.h>
#define ii pair<int, int>
#define x first
#define y second
#define mp make_pair
using namespace std;
ii bd;
int m, n, ans = 0;
string a, tmp;
char f[100001];
bool check[10001][10001];
int dx[5] = {0, 0, 1, -1};
int dy[5] = {1, -1, 0, 0};
void inp()
{

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            check[i][j] = true;

    for (int i = 1; i <= m; i++)
    {
        cin >> a;
        for (int j = 1; j <= n; j++)
        {
            if (a[j - 1] == '#')
                check[i][j] = false;
            if (a[j - 1] == '*')
                bd = make_pair(i, j);
        }
    }
}
bool thoat(int x, int y)
{
    return x == 1 || y == 1 || x == m || y == n;
}
void bfs(int x, int y)
{
    queue<ii> q;
    q.push(mp(x, y));
    check[x][y] = false;
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++)
        {
            if (check[u.x + dx[i]][u.y + dy[i]])
            {
                if (i == 0)
                    tmp += 'E';
                else if (i == 1)
                    tmp += 'W';
                else if (i == 2)
                    tmp += 'S';
                else
                    tmp += 'N';
                if (thoat(x + dx[i], y + dy[i]))
                {
                    cout << tmp;
                    return;
                }
                q.push(mp(u.x + dx[i], u.y + dy[i]));
                check[u.x + dx[i]][u.y + dy[i]] = false;
            }
        }
    }
}
int main()
{
    freopen("labyrinth.inp", "r", stdin);
    freopen("labyrinth.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp();
    bfs(bd.x, bd.y);
    return 0;
}
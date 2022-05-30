#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 1003;

int m, n, trai[maxn][maxn], tc, tf;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void preset()
{
    for (int i = 0; i <= m + 1; i++)
        trai[i][0] = trai[i][n + 1] = 1;
    for (int j = 0; j <= n + 1; j++)
        trai[0][j] = trai[m + 1][j] = 1;
}

void input()
{
    string tmp;
    for (int i = 1; i <= m; i++)
    {
        cin >> tmp;
        for (int j = 1; j <= n; j++)
        {
            if (tmp[j - 1] == '#')
                trai[i][j] = 1;
            else if (tmp[j - 1] == 'c')
                trai[i][j] = 2;
            else if (tmp[j - 1] == 'f')
                trai[i][j] = 3;
            else
                trai[i][j] = 0;
        }
    }
}

void bfs()
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (trai[i][j] != 1)
            {
                int cnt_c = 0, cnt_f = 0;
                queue<ii> q;
                q.push(mp(i, j));
                while (!q.empty())
                {
                    ii u = q.front();
                    q.pop();

                    if (trai[u.X][u.Y] == 2)
                        cnt_c++;
                    if (trai[u.X][u.Y] == 3)
                        cnt_f++;

                    trai[u.X][u.Y] = 1;
                    for (int k = 0; k < 4; k++)
                        if (trai[u.X + dx[k]][u.Y + dy[k]] != 1)
                            q.push(mp(u.X + dx[k], u.Y + dy[k]));
                }

                if (cnt_c > cnt_f)
                    tc += cnt_c;
                else
                    tf += cnt_f;
            }
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("mtntrai.inp", "r", stdin);
    freopen("mtntrai.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    preset();
    tc = 0, tf = 0;
    input();
    bfs();
    cout << tf << " " << tc;
    return 0;
}
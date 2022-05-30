#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(A) A.size()

const int maxn = 105;
bool visited[maxn][maxn];
int f[maxn][maxn], row, col;
ii st, des;

void reset()
{
    for (int i = 0; i <= col; i++)
        for (int j = 0; j <= row; j++)
            f[i][j] = visited[i][j] = 0;

    for (int i = 0; i <= row + 1; i++)
        visited[i][0] = visited[i][col + 1] = 1;
    for (int j = 0; j <= col + 1; j++)
        visited[0][j] = visited[row + 1][j] = 1;
}

void input()
{
    string s;
    for (int i = 1; i <= row; i++)
    {
        cin >> s;
        for (int j = 1; j <= col; j++)
        {
            if (s[j - 1] == 'B')
                st = mp(i, j);
            if (s[j - 1] == '*')
                visited[i][j] = 1;
            if (s[j - 1] == 'C')
                des = mp(i, j);
        }
    }
}

void bfs(int x, int y)
{
    queue<ii> q;
    q.push(mp(x, y));
    f[x][y] = visited[x][y] = 1;
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();

        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
            {
                if ((i == 0 && j == 0) || (i != 0 && j != 0))
                    continue;
                if (mp(u.fi + i, u.se + j) == des)
                {
                    cout << f[u.fi][u.se];
                    return;
                }
                if (!visited[u.fi + i][u.se + j])
                {
                    visited[u.fi + i][u.se + j] = 1;
                    f[u.fi + i][u.se + j] = f[u.fi][u.se] + 1;
                    q.push(mp(u.fi + i, u.se + j));
                }
            }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("vmunch.inp", "r", stdin);
    freopen("vmunch.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> row >> col;
    reset();
    input();
    bfs(st.fi, st.se);
    return 0;
}

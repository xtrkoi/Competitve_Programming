#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 505, th = 250005;
int m, n, arr[maxn][maxn];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bitset<th> res;
int len;
ii path[maxn][maxn];
queue<ii> q, cont[2];
deque<queue<ii>> qv;

void input()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
}

void trace(int i, int j)
{
    if (i == 1 && j == 1)
    {
        cout << arr[1][1];
        return;
    }
    trace(path[i][j].X, path[i][j].Y);
    cout << arr[i][j];
}

bool inside(int i, int j)
{
    return (i > 0) && (i <= m) && (j > 0) && (j <= n);
}

void clear(queue<ii> &a)
{
    while (!a.empty())
        a.pop();
}

void bfs()
{
    q.push(mp(1, 1));
    qv.pb(q);
    while (!qv.empty())
    {
        q = qv.front();
        clear(cont[0]);
        clear(cont[1]);
        while (!q.empty())
        {
            ii u = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                ii v = mp(u.X + dx[k], u.Y + dy[k]);
                if (inside(v.X, v.Y) && arr[v.X][v.Y] < 2 && path[v.X][v.Y] == mp(0, 0))
                {
                    path[v.X][v.Y] = u;
                    cont[arr[v.X][v.Y]].push(v);
                }
            }
        }
        if (!cont[1].empty())
            qv.pb(cont[1]);
        if (!cont[0].empty())
            qv.pb(cont[0]);
        qv.pop_front();
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("nktable.inp", "r", stdin);
    freopen("nktable.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    bfs();
    trace(m, n);
    return 0;
}

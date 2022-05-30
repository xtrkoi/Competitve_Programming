#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> ii;

const int maxn = 103, INF = 1e9;
int m, n, area[maxn][maxn], steps[maxn][maxn];
ii st, fi;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> area[i][j];
    int u, v;
    cin >> u >> v;
    st = mp(u, v);
    cin >> u >> v;
    fi = mp(u, v);
}

void bfs()
{
    queue<ii> q;
    q.push(st);
    steps[st.X][st.Y] = 0;
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int dis;
            if (area[u.X + dx[k]][u.Y + dy[k]] != area[u.X][u.Y])
                dis = steps[u.X][u.Y] + 3 + abs(area[u.X + dx[k]][u.Y + dy[k]] - area[u.X][u.Y]);
            else
                dis = steps[u.X][u.Y] + 1;

            if (steps[u.X + dx[k]][u.Y + dy[k]] > dis)
            {
                steps[u.X + dx[k]][u.Y + dy[k]] = dis;
                q.push(mp(u.X + dx[k], u.Y + dy[k]));
            }
        }
    }
}

void run()
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            steps[i][j] = INF;

    bfs();
}

int main()
{
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    cout << steps[fi.X][fi.Y];
    return 0;
}
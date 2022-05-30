#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 505;
int n, k, res;
bool arr[maxn][maxn], moved[2][maxn][maxn];
int dx[2][3] = {{1, 1, 0}, {1, 1, 0}};
int dy[2][3] = {{0, 1, 1}, {0, -1, -1}};
queue<ii> st[2];

void input()
{
    cin >> n >> k;
    while (k--)
    {
        int i, j;
        cin >> i >> j;
        arr[i][j] = 1;
    }
}

void run()
{
    st[0].push(mp(1, 1));
    moved[0][1][1] = 1;
    st[1].push(mp(1, n));
    moved[1][1][n] = 1;

    int robot = 0;
    res = 0;

    while (true)
    {
        if (robot == 1)
            res++;
        int sz = sz(st[robot]);
        while (sz--)
        {
            int i = st[robot].front().X, j = st[robot].front().Y;
            st[robot].pop();
            moved[robot][i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                int u = i + dx[robot][k], v = j + dy[robot][k];
                if (u < 1 || v < 1 || u > n || v > n || arr[u][v])
                    continue;
                if (robot == 1 && moved[0][u][v])
                {
                    cout << res << "\n";
                    return;
                }
                st[robot].push(mp(u, v));
            }
        }
        sz = sz(st[robot]);
        while (sz--)
        {
            ii u = st[robot].front();
            st[robot].pop();
            if (!moved[robot][u.X][u.Y])
            {
                st[robot].push(u);
                moved[robot][u.X][u.Y] = 1;
            }
        }
        robot ^= 1;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("robocon.inp", "r", stdin);
    freopen("robocon.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
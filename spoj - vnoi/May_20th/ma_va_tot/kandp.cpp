#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 6000;
ii m, t;
// turn 0 => knight, 1 => pawn
int turn, res;
int origin = maxn / 2, dis[maxn][maxn];
bool moved[maxn][maxn];
int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};
queue<ii> st;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("kandp.inp", "r", stdin);
    freopen("kandp.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m.X >> m.Y >> t.X >> t.Y >> turn;

    if (turn == 1)
    {
        turn = 0;
        t.X--;
    }

    if ((m.X - t.X + m.Y - t.Y) % 2 == 0)
    {
        cout << "NO\n";
        return 0;
    }

    st.push(m);
    dis[m.X + origin][m.Y + origin] = 1;
    moved[m.X + origin][m.Y + origin] = 1;

    int dX = abs(m.X - t.X) + 30, dY = abs(m.Y - t.Y) + 30;

    while (true)
    {
        if (turn == 1)
        {
            t.X--;
            for (int k = 0; k < 8; k++)
                if (moved[t.X + dx[k] + origin][t.Y + dy[k] + origin])
                {
                    cout << "YES\n"
                         << res + 1;
                    return 0;
                }
        }
        else
        {
            res++;
            int sz = sz(st);
            while (sz--)
            {
                ii u = st.front();
                st.pop();
                moved[u.X + origin][u.Y + origin] = false;
                for (int k = 0; k < 8; k++)
                {
                    int i = u.X + dx[k], j = u.Y + dy[k];
                    if (dis[i + origin][j + origin])
                        continue;
                    if (abs(i - t.X) > dX || abs(j - t.Y) > dY)
                        continue;
                    if (j < -1002 || j > 1002) // out of bound
                        continue;
                    st.push(mp(i, j));
                    dis[i + origin][j + origin] = 1;
                    moved[i + origin][j + origin] = true;
                }
            }
        }
        turn ^= 1;
    }
    return 0;
}
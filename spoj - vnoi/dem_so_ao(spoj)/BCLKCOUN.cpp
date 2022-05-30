#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 102;
int n, m, cnt = 0;
bool water[maxn][maxn];

void preset()
{
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            water[i][j] = 0;
}

void input()
{
    string tmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        for (int j = 1; j <= m; j++)
            if (tmp[j - 1] == 'W')
                water[i][j] = true;
    }
}

void bfs()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (water[i][j])
            {
                cnt++;
                queue<ii> q;
                q.push(mp(i, j));
                water[i][j] = false;
                while (!q.empty())
                {
                    ii u = q.front();
                    q.pop();
                    for (int k = -1; k <= 1; k++)
                        for (int l = -1; l <= 1; l++)
                        {
                            if (k == 0 && l == 0)
                                continue;
                            if (water[u.X + k][u.Y + l])
                            {
                                water[u.X + k][u.Y + l] = false;
                                q.push(mp(u.X + k, u.Y + l));
                            }
                        }
                }
            }
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("bclkcoun.inp", "r", stdin);
    freopen("bclkcoun.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    preset();
    input();
    bfs();
    cout << cnt;
    return 0;
}
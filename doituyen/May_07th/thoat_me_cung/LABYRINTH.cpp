#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef pair<int, int> ii;

const int maxn = 1e3 + 7;

int n, m;
vector<vector<int> > steps(maxn, vector<int>(maxn, 0));
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool seen[maxn][maxn];
ii start;

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
                seen[i][j] = true;
            if (s[j - 1] == '.')
                seen[i][j] = false;
            if (s[j - 1] == '*')
            {
                start = mp(i, j);
                seen[i][j] = false;
            }
        }
    }
}

bool escape(int x, int y)
{
    return x == 1 || y == 1 || x == m || y == n;
}

void bfs(int x, int y)
{
    if (escape(x, y))
    {
        cout << "0";
        exit(0);
    }
    seen[x][y] = true;
    queue<ii > q;
    q.push(mp(x, y));
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            if (!seen[u.X + dx[k]][u.Y + dy[k]])
            {
                seen[u.X + dx[k]][u.Y + dy[k]] = true;
                steps[u.X + dx[k]][u.Y + dy[k]] = steps[u.X][u.Y] + 1;
                q.push(mp(u.X + dx[k], u.Y + dy[k]));
                if (escape(u.X + dx[k], u.Y + dy[k]))
                {
                    cout << steps[u.X + dx[k]][u.Y + dy[k]];
                    exit(0);
                }
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
    input();
    bfs(start.X, start.Y);
}
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef pair<int, int> ii;
typedef long long ll;

const int maxn = 1e6 + 7, maxs = 1e3 + 7;
int n, lives;
vector<vector<ll> > treasure(maxs, vector<ll>(maxs, 0LL));
vector<ll> treasure_count;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input()
{
    cin >> n >> lives;
    int x, y;
    ll p;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> p;
        treasure[x][y] = p;
    }
}

ll collect(int x, int y)
{
    ll cnt = treasure[x][y];
    treasure[x][y] = 0;
    queue<ii > q;
    q.push(mp(x, y));
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
            if (treasure[u.X + dx[k]][u.Y + dy[k]] > 0)
            {
                cnt += treasure[u.X + dx[k]][u.Y + dy[k]];
                treasure[u.X + dx[k]][u.Y + dy[k]] = 0;
                q.push(mp(u.X + dx[k], u.Y + dy[k]));
            }
    }
    return cnt;
}

void bfs()
{
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
            if (treasure[i][j] > 0)
                treasure_count.pb(collect(i, j));
}

int main()
{
    freopen("treasure.inp", "r", stdin);
    freopen("treasure.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    bfs();
    ll res = 0;
    sort(treasure_count.begin(), treasure_count.end(), greater<ll>());
    for (int i = 0; i < lives; i++)
        res += treasure_count[i];
    cout << res;
    return 0;
}
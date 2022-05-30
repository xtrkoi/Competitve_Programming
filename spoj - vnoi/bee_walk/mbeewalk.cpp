#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

const int maxn = 102;
int n;
ll dp[3 * maxn][3 * maxn][20];
vector<vvb> seen(3 * maxn, vvb(3 * maxn, vb(20, false)));
int dx[6] = {0, 0, -1, -1, 1, 1};
int dy[6] = {2, -2, -1, 1, -1, 1};

void run()
{
    queue<pair<ii, int>> q;
    q.push(mp(mp(100, 100), 0));
    dp[100][100][0] = 1;
    while (!q.empty())
    {
        int u = q.front().X.X;
        int v = q.front().X.Y;
        int j = q.front().Y;
        q.pop();
        if (seen[u][v][j])
            continue;
        seen[u][v][j] = true;
        if (j == 14)
            continue;
        for (int k = 0; k < 6; k++)
        {
            int x = u + dx[k];
            int y = v + dy[k];
            dp[x][y][j + 1] += dp[u][v][j];
            q.push(mp(mp(x, y), j + 1));
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("mbeewalk.inp", "r", stdin);
    freopen("mbeewalk.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << dp[100][100][n] << "\n";
    }
    return 0;
}
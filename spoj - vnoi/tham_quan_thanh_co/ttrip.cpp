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

const int INF = 1e9, maxn = 102;
int n;
int adj[maxn][maxn];
vector<bool> seen(maxn, false);

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 0)
                adj[i][j] = INF;
        }
}

void find_path()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (adj[i][j] != INF)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("ttrip.inp", "r", stdin);
    freopen("ttrip.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    find_path();
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         if (adj[i][j] == INF)
    //             cout << "- ";
    //         else
    //             cout << adj[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    int res = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        if (seen[i])
            continue;
        seen[i] = true;

        int mn = INF;
        for (int j = 1; j <= n; j++)
        {
            if (mn > adj[i][j] && adj[i][j] != INF)
                mn = adj[i][j];
        }
        for (int j = 1; j <= n; j++)
            if (adj[i][j] == mn && adj[i][j] != INF)
                q.push(j);
        res += mn;
    }
    cout << res;
    return 0;
}
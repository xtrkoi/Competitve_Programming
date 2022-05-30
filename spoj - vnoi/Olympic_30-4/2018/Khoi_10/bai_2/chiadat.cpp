#include <bits/stdc++.h>
using namespace std;

const int maxn = 505, INF = 1e9;
int ul[maxn][maxn], ur[maxn][maxn], bl[maxn][maxn], br[maxn][maxn], arr[maxn][maxn], n, sum_tree = 0, res = INF;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            sum_tree += arr[i][j];
        }
}

void prepare()
{
    for (int i = 0; i <= n; i++)
        ul[0][i] = ul[i][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ul[i][j] = ul[i - 1][j] + ul[i][j - 1] - ul[i - 1][j - 1] + arr[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
        }
}

void run()
{
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            int max_tree = max({ul[i][j], ur[i][j + 1], bl[i + 1][j], br[i + 1][j + 1]});
            int min_tree = min({ul[i][j], ur[i][j + 1], bl[i + 1][j], br[i + 1][j + 1]});
            res = min(res, max_tree - min_tree);
        }
    cout << res;
}

int main()
{
    freopen("chiadat.inp", "r", stdin);
    freopen("chiadat.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    prepare();
    run();
    return 0;
}
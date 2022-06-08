#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 2e9;
int n;
vii arr;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("mindist.inp", "r", stdin);
    freopen("mindist.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.pb(mp(tmp, i));
    }
    sort(arr.begin(), arr.end());
    int res = INF;
    for (int i = 1; i < n; i++)
        if (arr[i - 1].X == arr[i].X)
            res = min(res, abs(arr[i].Y - arr[i - 1].Y));
    if (res == INF)
        cout << "-1";
    else
        cout << res;
    return 0;
}
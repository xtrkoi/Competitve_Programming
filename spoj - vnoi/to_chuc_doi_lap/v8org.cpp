#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxn = 1e5 + 5, INF = 2e9;
int n, k;
vi parent(maxn), children(maxn);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("v8org.inp", "r", stdin);
    freopen("v8org.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
        for (int j = parent[i]; j; j = parent[j])
            children[j]++;
    }

    int res = 0;

    for (int i = n; i >= 1; i--)
        if (children[i] + 1 >= k)
        {
            res++;
            for (int j = parent[i]; j; j = parent[j])
                children[j] -= children[i] + 1;
        }
    cout << res;
    return 0;
}
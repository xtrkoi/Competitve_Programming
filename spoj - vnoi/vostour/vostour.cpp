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

const int maxn = 5005;
int c, f, t;
vector<vi> adj(maxn);

void input()
{
    cin >> c >> t >> f;
    int u, v;
    for (int i = 0; i < f; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("vostour.inp", "r", stdin);
    freopen("vostour.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}
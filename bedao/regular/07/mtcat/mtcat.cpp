#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 1e6 + 2;
int n;
vector<int> h(maxn), J(maxn);

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> J[i];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("mtcat.inp", "r", stdin);
    freopen("mtcat.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}
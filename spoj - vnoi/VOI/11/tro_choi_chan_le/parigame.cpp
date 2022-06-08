#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;

int n, k;

void input()
{
    cin >> n;
}

void run();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("parigame.inp", "r", stdin);
    freopen("parigame.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    while (k--)
    {
        input();
        run();
    }
    return 0;
}
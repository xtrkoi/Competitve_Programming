#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int n;
ll u, v;
vector<pll> list_of_vectors_1, list_of_vectors_2, sum_vector1, sum_vector2;

void input()
{
    cin >> n;
    for (int i = 0; i < n / 2; i++)
    {
        int x, y;
        cin >> x >> y;
        list_of_vectors_1.pb((mp(x, y)));
    }
    for (int i = n / 2; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        list_of_vectors_2.pb(mp(x, y));
    }
    cin >> u >> v;
}

void initiate(int i, vector<pll> &list_of_vectors, vector<pll> &sum)
{
}
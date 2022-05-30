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

int n;
vector<ii> arr;

struct ranges
{
    int x, y, k;
    ranges()
    {
        x = y = k = 0;
    }
    ranges(int a, int b, int c)
    {
        x = a;
        y = b;
        k = c;
    }
};

bool comp(const ii &a, const ii &b)
{
    return a.X > b.X || (a.X == b.X && a.Y < b.Y);
    arr.pb({1, 1});
}

void input()
{
    cin >> n;
    ii tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp.X >> tmp.Y;
        arr.pb(tmp);
    }
    sort(arr.begin(), arr.end(), comp);
}
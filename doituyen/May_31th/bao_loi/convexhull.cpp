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

const ll INF = 2e18;
struct pt
{
    ll x, y;
    pt()
    {
        x = y = 0;
    }
    pt(ll a, ll b)
    {
        x = a;
        y = b;
    }
};
vector<pt> points, vertex;
int n, d = 0;
pt pivot;

void input()
{
    cin >> n;
    pt mn = pt(INF, INF);
    pt tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp.x >> tmp.y;
        if (tmp.y < mn.y || (tmp.y == mn.y && tmp.x < mn.x))
        {
            mn = tmp;
            d = i;
        }
        points.pb(tmp);
    }
}

ll cp(const pt &a, const pt &b, const pt &c)
{
    return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}

int turnLeft(const pt &a, const pt &b, const pt &c)
{
    ll tmp = cp(a, b, c);
    if (tmp > 0)
        return 1;
    if (tmp < 0)
        return -1;
    return 0;
}

bool comp(const pt &a, const pt &b)
{
    int tmp = turnLeft(a, b, pivot);
    if (tmp != 0)
        return tmp > 0;
    if (a.x >= pivot.x)
        return a.x < b.x;
    else
        return a.x > b.x;
}

void run1()
{
    pivot = points[d];
    points.erase(points.begin() + d);
    sort(points.begin(), points.end(), comp);
    points.pb(pivot);
    vertex.pb(pivot);
    vertex.pb(points[0]);
    points.erase(points.begin());
    for (pt i : points)
    {
        pt tmp = vertex.back();
        vertex.pop_back();
        while (!vertex.empty() && turnLeft(tmp, i, vertex.back()) <= 0)
        {
            tmp = vertex.back();
            vertex.pop_back();
        }
        vertex.pb(tmp);
        vertex.pb(i);
    }
    vertex.pop_back();
    cout << sz(vertex) << "\n";
}

void run2()
{
    long double area = 0;
    for (int i = 0; i < sz(vertex) - 1; i++)
        area += cp(vertex[i], vertex[i + 1], pt(0, 0));
    area += cp(vertex.back(), pivot, pt(0, 0));
    cout << setprecision(1) << fixed;
    cout << abs(area / 2) << "\n";
}

void run3()
{
    for (pt i : vertex)
        cout << i.x << " " << i.y << "\n";
}

int main()
{
    freopen("convexhull.inp", "r", stdin);
    freopen("convexhull.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run1();
    run2();
    run3();
    return 0;
}

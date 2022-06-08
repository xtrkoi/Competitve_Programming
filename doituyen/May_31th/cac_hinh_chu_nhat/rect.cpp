#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

const ll INF = 2e18, maxn = 1e3 + 5;
struct pt
{
    ld x, y;
    pt()
    {
        x = y = 0;
    }
    pt(ld a, ld b)
    {
        x = a;
        y = b;
    }
};

struct rec
{
    pt corner[4], center;
    ld find_min(ld a, ld b, ld c, ld d)
    {
        return min(a, min(b, min(c, d)));
    }
    ld find_max(ld a, ld b, ld c, ld d)
    {
        return max(a, max(b, max(c, d)));
    }
    rec()
    {
        corner[0] = corner[1] = corner[2] = corner[3] = center = pt(0, 0);
    }
    rec(pt a, pt b, pt c, pt d)
    {
        corner[0] = a;
        corner[1] = b;
        corner[2] = c;
        corner[3] = d;
        ld up = find_max(a.y, b.y, c.y, d.y);
        ld dw = find_min(a.y, b.y, c.y, d.y);
        ld lt = find_min(a.x, b.x, c.x, d.x);
        ld rt = find_max(a.x, b.x, c.x, d.x);
        center = pt((lt + rt) / 2, (up + dw) / 2);
    }
};
int n;
vector<rec> arr;
vi tag(maxn), vol(maxn, 1);

void input()
{
    cin >> n;
    ld a1, a2, b1, b2, c1, c2, d1, d2;
    for (int i = 0; i < n; i++)
    {
        cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2;
        arr.pb(rec(pt(a1, a2), pt(b1, b2), pt(c1, c2), pt(d1, d2)));
    }
    cout << setprecision(1) << fixed;
}

int find(int x)
{
    if (x == tag[x])
        return x;
    return tag[x] = find(tag[x]);
}

bool same(int a, int b)
{
    return find(a) == find(b);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (vol[a] < vol[b])
        swap(a, b);
    tag[b] = a;
    vol[a] += vol[b];
}

ld cp(const pt &a, const pt &b, const pt &c)
{
    return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}

int CCW(const pt &a, const pt &b, const pt &c)
{
    ld tmp = cp(a, b, c);
    if (tmp == 0)
        return 0;
    return (tmp > 0 ? 1 : -1);
}

bool in_middle(const pt &a, const pt &b, const pt &m)
{
    return min(a.x, b.x) <= m.x && m.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= m.y && m.y <= max(a.y, b.y);
}

bool pass(const pt &a1, const pt &a2, const pt &b1, const pt &b2)
{
    int tmp1 = CCW(a1, b1, a2);
    int tmp2 = CCW(a1, b2, a2);
    int tmp3 = CCW(b1, a1, b2);
    int tmp4 = CCW(b1, a2, b2);
    int ans1 = tmp1 * tmp2;
    int ans2 = tmp3 * tmp4;
    if (ans1 != 0 || ans2 != 0)
        return (ans1 <= 0 && ans2 <= 0 ? true : false);
    return (in_middle(a1, a2, b1) ||
            in_middle(a1, a2, b2) ||
            in_middle(b1, b2, a1) ||
            in_middle(b1, b2, a2));
}

bool inside(const rec &c, const rec &d)
{
    for (int i = 0; i < 4; i++)
        if (pass(c.center, d.center, c.corner[i], c.corner[(i + 1) % 4]) ||
            pass(c.center, d.center, d.corner[i], d.corner[(i + 1) % 4]))
            return false;
    return true;
}

bool connect(const rec &c, const rec &d)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (pass(c.corner[i], c.corner[(i + 1) % 4], d.corner[j], d.corner[(j + 1) % 4]))
                return true;
    return false;
}

void run()
{
    for (int i = 0; i < n; i++)
        tag[i] = i;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (!same(i, j) && (inside(arr[i], arr[j]) || connect(arr[i], arr[j])))
                merge(i, j);
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, vol[i]);
    cout << res;
}

int main()
{
    freopen("rect.inp", "r", stdin);
    freopen("rect.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
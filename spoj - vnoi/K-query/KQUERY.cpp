// Segmentation Fault
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e5 + 5, INF = 1e9;
int n, qn;
vector<ll> arr, id_a;
ll st[4 * maxn];

struct query
{
    int k;
    int l, r;
    int ps;
    query()
    {
        k = INF;
        l = 1;
        r = 1;
        ps = 1;
    }

    query(int a, int b, int c, int d)
    {
        k = a;
        l = b;
        r = c;
        ps = d;
    }
    /* bool operator<(const query &rhs) const
    {
        return tie(k, l, r, ps) < tie(rhs.k, rhs.l, rhs.r, ps);
    } */

    bool operator<(const query &rhs) const
    {
        return k < rhs.k;
    }
};

vector<query> Q;

void std_input()
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.pb(tmp);
        // b.pb(1);
    }
}

void Q_input()
{
    cin >> qn;
    int i, j, inp_k;
    for (int h = 0; h < qn; h++)
    {
        cin >> i >> j >> inp_k;
        Q.pb(query(inp_k, i, j, h));
    }
}

void sort_arr()
{
    vector<ii> tmp;
    for (int i = 0; i < n; i++)
        tmp.pb(mp(arr[i], i));
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++)
        id_a.pb(tmp[i].second);
}

void build(int id, int lt, int rt)
{
    if (lt == rt)
    {
        st[id] = 1;
        return;
    }

    int mid = (lt + rt) / 2;
    build(id * 2, lt, mid);
    build(id * 2 + 1, mid + 1, rt);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(int id, int lt, int rt, int p)
{
    if (p < lt || rt < p)
        return;
    if (lt == rt)
    {
        st[id] = 0;
        return;
    }

    int mid = (lt + rt) / 2;
    update(id * 2, lt, mid, p);
    update(id * 2 + 1, mid + 1, rt, p);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get_value(int id, int lt, int rt, int qs, int qe)
{
    if (rt < qs || qe < lt)
        return 0;
    if (qs <= lt && rt <= qe)
        return st[id];

    int mid = (lt + rt) / 2;
    return get_value(id * 2, lt, mid, qs, qe) + get_value(id * 2 + 1, mid + 1, rt, qs, qe);
}

void run()
{
    std_input();
    Q_input();
    sort_arr();
    build(1, 1, n);
    sort(Q.begin(), Q.end());
    vector<ii> res;
    int i = 0;
    for (int h = 0; h < qn; h++)
    {
        while (arr[id_a[i]] <= Q[h].k && i < n)
        {
            // b[id_a[i]] = 0;
            update(1, 1, n, id_a[i] + 1);
            i++;
        }
        int tmp = get_value(1, 1, n, Q[h].l, Q[h].r);
        res.pb(mp(Q[h].ps, tmp));
    }
    sort(res.begin(), res.end());
    for (int h = 0; h < qn; h++)
        cout << res[h].second << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("kquery.inp", "r", stdin);
    freopen("kquery.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
    return 0;
}
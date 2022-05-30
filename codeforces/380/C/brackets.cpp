#include <bits/stdc++.h>
using namespace std;

#define sz(A) A.size()

// maximum length of the string
const int maxn = 1e6 + 5;

// string storing brackets
string s;

// data type for each node in the segment tree
struct node
{
    // optimal: number of pairs of opening-closing brackets
    // open: number of opening brackets
    // close: number of closing brackets
    int optimal;
    int open;
    int close;

    // default assigning function
    node()
    {
        optimal = 0;
        open = 0;
        close = 0;
    }

    // assign values to the node
    node(int opt, int o, int c)
    {
        optimal = opt;
        open = o;
        close = c;
    }
};

// array storing segment tree
node st[maxn * 4];

// combine two nodes
node operator+(const node &left, const node &right)
{
    // combining result
    node res;

    // number of bracket-pairs
    int tmp = min(left.open, right.close);

    res.optimal = left.optimal + right.optimal + tmp;

    res.open = left.open + right.open - tmp;
    res.close = left.close + right.close - tmp;

    return res;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        if (s[l] == '(')
            st[id] = node(0, 1, 0);
        else
            st[id] = node(0, 0, 1);
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

node query(int id, int l, int r, int qs, int qe)
{
    if (qe < l || qs > r)
        return node(0, 0, 0);

    if (qs <= l && r <= qe)
        return st[id];

    int mid = (l + r) / 2;
    return query(id * 2, l, mid, qs, qe) + query(id * 2 + 1, mid + 1, r, qs, qe);
}

void run()
{
    int start, end;
    cin >> start >> end;
    cout << query(1, 1, sz(s), start, end).optimal * 2 << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("brackets.inp", "r", stdin);
    freopen("brackets.out", "w", stdout);
#endif // !ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    build(1, 0, sz(s) - 1);
    int testcase;
    cin >> testcase;
    while (testcase--)
        run();
    return 0;
}
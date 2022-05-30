#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef vector<int> vi;
typedef pair<int, int> ii;

const int maxn = 2001, th = 2005;
int res;
bool arr[th][th];
int lt[th], rt[th], up[th], dw[th];
int row[th][th], col[th][th];
queue<ii> st;

void initialize()
{
    for (int i = 0; i <= maxn + 1; i++)
    {
        lt[i] = dw[i] = maxn + 1, rt[i] = up[i] = 0;
        for (int j = 0; j <= maxn + 1; j++)
        {
            row[i][j] = j;
            col[j][i] = i;
        }
    }
}

void input()
{
    int n;
    cin >> n;
    while (n--)
    {
        int i, j;
        cin >> i >> j;
        i += 1001;
        j += 1001;
        if (arr[i][j])
            continue;
        arr[i][j] = true;
        st.push(mp(i, j));
        lt[i] = min(lt[i], j);
        rt[i] = max(rt[i], j);
        dw[j] = min(dw[j], i);
        up[j] = max(up[j], i);
    }
}

// Disjoint-set Union - DSU

int find_row(int i, int j)
{
    if (row[i][j] == j)
        return j;
    return row[i][j] = find_row(i, row[i][j]);
}

int find_col(int j, int i)
{
    if (col[j][i] == i)
        return i;
    return col[j][i] = find_col(j, col[j][i]);
}

void bfs()
{
    while (!st.empty())
    {
        int i = st.front().X, j = st.front().Y;
        st.pop();

        int lft = lt[i], rgt = rt[i];
        for (int k = find_row(i, lft); k <= rgt; k = find_row(i, k + 1))
        {
            row[i][k] = k + 1;
            if (arr[i][k])
                continue;
            arr[i][k] = true;
            st.push(mp(i, k));
            dw[k] = min(dw[k], i);
            up[k] = max(up[k], i);
        }

        int dwn = dw[j], up2 = up[j];
        for (int k = find_col(j, dwn); k <= up2; k = find_col(j, k + 1))
        {
            col[j][k] = k + 1;
            if (arr[k][j])
                continue;
            arr[k][j] = true;
            st.push(mp(k, j));
            lt[k] = min(lt[k], j);
            rt[k] = max(rt[k], j);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("pbcpoint.inp", "r", stdin);
    freopen("pbcpoint.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    initialize();
    input();
    bfs();

    res = 0;
    for (int i = 1; i <= maxn; i++)
        for (int j = 1; j <= maxn; j++)
            res += arr[i][j];
    cout << res;
    return 0;
}
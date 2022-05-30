#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;

struct board
{
    int b[4][4];
};

const int maxn = 1e5 + 5;
vi dis(maxn);
board start;
queue<board> state;

int getBin(board x)
{
    int res = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            res = res * 2 + x.b[i][j];
    return res;
}

board input()
{
    board res;
    for (int i = 0; i < 4; i++)
    {
        string s;
        getline(cin, s);
        for (int j = 0; j < 4; j++)
            res.b[i][j] = s[j] - '0';
    }
    return res;
}

void psh(board a, int cnt)
{
    state.push(a);
    dis[getBin(a)] = cnt;
}

void up(int x, int y, board a, int cnt)
{
    if (x == 0 || a.b[x - 1][y] == 1)
        return;
    swap(a.b[x][y], a.b[x - 1][y]);
    if (!dis[getBin(a)])
        psh(a, cnt);
}

void dw(int x, int y, board a, int cnt)
{
    if (x == 3 || a.b[x + 1][y] == 1)
        return;
    swap(a.b[x][y], a.b[x + 1][y]);
    if (!dis[getBin(a)])
        psh(a, cnt);
}

void lt(int x, int y, board a, int cnt)
{
    if (y == 0 || a.b[x][y - 1] == 1)
        return;
    swap(a.b[x][y], a.b[x][y - 1]);
    if (!dis[getBin(a)])
        psh(a, cnt);
}

void rt(int x, int y, board a, int cnt)
{
    if (y == 3 || a.b[x][y + 1] == 1)
        return;
    swap(a.b[x][y], a.b[x][y + 1]);
    if (!dis[getBin(a)])
        psh(a, cnt);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("chesscbg.inp", "r", stdin);
    freopen("chesscbg.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    start = input();
    psh(start, 1);
    start = input();

    while (!state.empty())
    {
        board u = state.front();
        state.pop();
        if (getBin(u) == getBin(start))
            break;
        int cnt = dis[getBin(u)] + 1;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (u.b[i][j] == 1)
                {
                    up(i, j, u, cnt);
                    dw(i, j, u, cnt);
                    lt(i, j, u, cnt);
                    rt(i, j, u, cnt);
                }
    }
    cout << dis[getBin(start)] - 1;
    return 0;
}
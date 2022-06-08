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

struct state
{
    int clock[3][3];
};
state st;
queue<state> q;
bool make_move[9][9] = {{1, 1, 0, 1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 1, 0, 1, 1, 1, 0, 1, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0, 1},
                        {0, 0, 0, 1, 1, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 1, 1, 1},
                        {0, 0, 0, 0, 1, 1, 0, 1, 1}};
bool seen[270000];
int res = 0;

int get_string(state x)
{
    int ans = 0, expo = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            ans += x.clock[i][j] * expo;
            expo *= 4;
        }
    return ans;
}

void input()
{
    for (int i = 0; i < 3; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 3; j++)
            st.clock[i][j] = s[j] - '0';
    }
}

state performMove(int k, state x)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            int c = i * 3 + j;
            int m = make_move[k][c];
            x.clock[i][j] = (x.clock[i][j] + m) % 4;
        }
    return x;
}

/* void printState(state x)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << x.clock[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
} */

void bfs()
{
    q.push(st);
    seen[get_string(st)] = true;
    while (true)
    {
        int sz = sz(q);
        res++;
        // cout << res << "\n";
        while (sz--)
        {
            state u = q.front();
            q.pop();
            for (int k = 0; k < 9; k++)
            {
                state v = performMove(k, u);
                // printState(v);
                int str_v = get_string(v);
                if (str_v == 0)
                {
                    cout << res;
                    return;
                }
                if (!seen[str_v])
                {
                    seen[str_v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("clock.inp", "r", stdin);
    freopen("clock.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    // printState(st);
    bfs();
    return 0;
}
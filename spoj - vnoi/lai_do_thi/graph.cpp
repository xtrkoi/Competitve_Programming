#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

const int maxv = 1002;
vvb adj;
vector<ii> edge_list;
string ins;
int n, tp;

void add_edge()
{
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    edge_list.pb(mp(u, v));
}

void del_edge()
{
    int u, v;
    cin >> u >> v;
    adj[u][v] = 0;
}

void del_any()
{
    if (!tp)
    {
        for (ii i : edge_list)
            if (adj[i.X][i.Y])
            {
                cout << i.X << " " << i.Y << "\n";
                adj[i.X][i.Y] = 0;
                return;
            }
    }
    else
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (adj[i][j])
                {
                    cout << i << " " << j << "\n";
                    adj[i][j] = 0;
                    return;
                }
    }
    cout << "-1\n";
}

void check_edge()
{
    int u, v;
    cin >> u >> v;
    if (adj[u][v])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("graph.inp", "r", stdin);
    freopen("graph.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ins = "START";
    while (true)
    {
        cin >> ins;
        if (ins == "END")
            break;
        if (ins == "NEW")
        {
            int k;
            cin >> n >> k;
            if (!k)
            {
                adj = vvb(n + 2, vb(n + 2, false));
                tp = 0;
            }
            else
            {
                adj = vvb(n + 2, vb(n + 2, true));
                tp = 1;
            }
            edge_list.clear();
        }
        if (ins == "ADD")
            add_edge();
        if (ins == "DEL")
            del_edge();
        if (ins == "ANY")
            del_any();
        if (ins == "EDG")
            check_edge();
    }
    return 0;
}
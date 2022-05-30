#include <bits/stdc++.h>
using namespace std;

#define pb push_back

struct mang
{
    int a, b, du;

    mang()
    {
        a = 0;
        b = 0;
        du = 0;
    }

    mang(int a2, int b2, int du2)
    {
        a = a2;
        b = b2;
        du = du2;
    }
};

int t, n;

void run(int x)
{
    queue<int> q;
    queue<mang> dd;

    q.push(6);
    q.push(8);

    dd.push(mang(0, 1, 6 % x));
    dd.push(mang(1, 0, 8 % x));

    mang u = dd.front();
    dd.pop();
    while (u.a + u.b <= 200 && u.du != 0)
    {
        int k = q.front();
        q.pop();

        q.push(6);
        dd.push(mang(u.a, u.b + 1, (u.du * 10 + 6) % x));

        if (k == 8)
        {
            q.push(8);
            dd.push(mang(u.a + 1, u.b, (u.du * 10 + 8) % x));
        }

        u = dd.front();
        dd.pop();
    }
    if (u.a + u.b > 200)
        cout << "-1\n";
    else
    {
        for (int i = 0; i < u.a; i++)
            cout << "8";
        for (int i = 0; i < u.b; i++)
            cout << "6";
        cout << "\n";
    }
}

int main()
{
    freopen("num86.inp", "r", stdin);
    freopen("num86.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n % 10 == 5)
            cout << "-1\n";
        else
            run(n);
    }
    return 0;
}
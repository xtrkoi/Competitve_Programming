#include <iostream>
using namespace std;
int a, b, c;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("vdsuccess.inp", "r", stdin);
    freopen("vdsuccess.out", "w", stdout);
#endif
    cin >> a >> b >> c;
	cout << a * 500 + b * 1000 + c * 1500;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int ifloor(double x) {return int(floor(x));}
int iceil(double x) {return int(ceil(x));}

vector<bool> vis;
void solve(double l, double r) {
    double rng = r-l;
    if (iceil(l+rng/3) > ifloor(r-rng/3)) {
        for (int a = iceil(l); a <= ifloor(r); a++) {
            if (!vis[a]) {cout << a << '\n'; vis[a] = true;}
        }
        return;
    }
    solve(l, l+rng/3);
    solve(r-rng/3, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);

    int n;
    cin >> n;
    vis = vector<bool>(n+1);
    solve(0, n);

    return 0;
}

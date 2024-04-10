#include <bits/stdc++.h>

using namespace std;

int ifloor(double x) {return int(floor(x));}
int iceil(double x) {return int(ceil(x));}

vector<bool> cycle;
bool is_valid(const long x, const long n) {
    // cout << x << ' ' << n << '\n';
    if (x == 0 || x == n) {return true;}
    long x1 = x*3;
    long dig = x1/n;
    x1 -= dig*n;
    if (dig == 1) {return x1 == 0;}
    else if (cycle[x]) {return true;}
    else {
        cycle[x] = 1;
        bool s = is_valid(x1, n);
        cycle[x] = 0;
        return s;
    }
}

int n;
void solve(double l, double r) {
    double rng = r-l;
    if (iceil(l+rng/3) > ifloor(r-rng/3)) {
        for (int i = iceil(l); i <= ifloor(r); i++) {
            // cout << "testing: " << i << '\n';
            if (is_valid(i, n)) {cout << i << '\n';}
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

    cin >> n;
    cycle = vector<bool>(n+1);
    solve(0, n);

    return 0;
}

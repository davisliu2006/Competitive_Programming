#include <bits/stdc++.h>

using namespace std;

struct node {
    int n0, n1;
    int l, c;
};

vector<int> par;
int dsu_find(int x) {
    if (par[x] == 0) {return x;}
    else {return par[x] = dsu_find(par[x]);}
}
void dsu_union(int x, int y) {
    int fx = dsu_find(x);
    int fy = dsu_find(y);
    assert(fx != fy);
    par[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);

    int n, m;
    cin >> n >> m;
    par = vector<int>(n+1);
    vector<node> edges(m);
    for (node& e: edges) {
        cin >> e.n0 >> e.n1 >> e.l >> e.c;
    }
    sort(edges.begin(), edges.end(), [](const node& x, const node& y) {
        return x.c < y.c;
    });
    long cst = 0;
    for (node& e: edges) {
        if (dsu_find(e.n0) != dsu_find(e.n1)) {
            dsu_union(e.n0, e.n1);
            cst += e.c;
        }
    }
    cout << cst << '\n';

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const int K = 200;

int n, k;
vector<long> arr(N+1);
vector<long> memo0(N+1);
vector<long> memo1(N+1);
int best_i0[K+1][N+1];
int cutnum = 1;

long ans_at(int i0, int i) {
    return (arr[i]-arr[i0])*arr[i0]+memo0[i0];
}
void solve_rng(int l, int r, int i0_l, int i0_r) {
    if (l > r) {return;}
    int i = (l+r)/2;
    int i0_best = i0_l;
    long ans_best = 0;
    for (int i0 = i0_l; i0 <= min(i0_r, i-1); i0++) {
        long tmp = ans_at(i0, i);
        if (tmp > ans_best) {
            i0_best = i0;
            ans_best = tmp;
        }
    }
    memo1[i] = ans_at(i0_best, i);
    best_i0[cutnum][i] = i0_best;
    solve_rng(l, i-1, i0_l, i0_best);
    solve_rng(i+1, r, i0_best, i0_r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    for (cutnum = 1; cutnum <= k; cutnum++) {
        swap(memo0, memo1);
        solve_rng(cutnum+1, n, cutnum, n-1);
    }
    cout << memo1[n] << '\n';

    while (k > 0) {
        cout << (n = best_i0[k][n]) << (k == 1? '\n' : ' ');
        k--;
    }

    return 0;
}

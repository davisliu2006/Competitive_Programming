#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);

    int n;
    cin >> n;
    vector<int> vec(n+2);
    vector<long> ans(n+2, LONG_MAX);
    ans[1] = 0;
    for (int a = 1; a <= n; a++) {
        cin >> vec[a];
    }

    // odd
    for (int a = 1; a <= n; a++) {
        long curr = 0;
        for (int b = 1; a-b >= 1 && a+b <= n; b++) {
            curr += abs(vec[a+b]-vec[a-b]);
            ans[b*2+1] = min(ans[b*2+1], curr);
        }
    }
    // even
    for (int a = 1; a <= n; a++) {
        long curr = 0;
        for (int b = 1; a-b >= 1 && a+b-1 <= n; b++) {
            curr += abs(vec[a+b-1]-vec[a-b]);
            ans[b*2] = min(ans[b*2], curr);
        }
    }
    for (int a = 1; a <= n; a++) {
        cout << ans [a] << ' ';
    }
    cout << '\n';

    return 0;
}

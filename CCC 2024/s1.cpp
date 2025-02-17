#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n/2; i++) {
        ans += (arr[i] == arr[i+n/2])*2;
    }
    cout << ans << '\n';

    return 0;
}

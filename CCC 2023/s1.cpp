#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);

    int n;
    cin >> n;
    vector<int> top(n+2);
    vector<int> bott(n+2);
    int cnt = 0;
    for (int a = 1; a <= n; a++) {
        cin >> top[a];
        if (top[a]) {
            cnt += 3;
            if (top[a-1]) {cnt -= 2;}
        }
    }
    for (int a = 1; a <= n; a++) {
        cin >> bott[a];
        if (bott[a]) {
            cnt += 3;
            if (bott[a-1]) {cnt -= 2;}
            if (a%2 == 1 && top[a]) {cnt -= 2;}
        }
    }
    cout << cnt << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);

    int t, n;
    cin >> t >> n;
    while (t--) {
        string str;
        cin >> str;
        vector<int> freq(26);
        vector<char> is_heavy(26);
        for (char& c: str) {
            c -= 'a';
            freq[c]++;
            if (freq[c] > 1) {is_heavy[c] = true;} 
        }
        bool ans = true;
        for (int i = 1; i < n; i++) {
            char c = str[i];
            char c0 = str[i-1];
            if (is_heavy[c] == is_heavy[c0]) {
                ans = false; break;
            }
        }
        cout << (ans? "T\n" : "F\n");
    }

    return 0;
}

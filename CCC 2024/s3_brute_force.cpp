#include <bits/stdc++.h>

using namespace std;

vector<int> arr0, arr1;
pair<bool, vector<pair<int,int>>> try_solve(int LB, int UB) {
    // try L
    vector<pair<int,int>> sol;
    int jmin = LB;
    bool possible = true;
    for (int i = LB; i <= UB; i++) {
        if (arr0[i] != arr1[i]) {
            jmin = max(jmin, i);
            for (int j = jmin; j <= UB; j++) {
                if (arr0[j] == arr1[i]) {
                    sol.push_back({i, j});
                    jmin = max(jmin, j);
                    break;
                } else if (j == UB) {
                    possible = false;
                    break;
                }
            }
        }
    }
    if (possible) {
        return {true, sol};
    } else {
        // try R
        sol.clear();
        int jmax = UB;
        possible = true;
        for (int i = UB; i >= LB; i--) {
            if (arr0[i] != arr1[i]) {
                jmax = min(jmax, i);
                for (int j = jmax; j >= LB; j--) {
                    if (arr0[j] == arr1[i]) {
                        sol.push_back({i, j});
                        jmax = min(jmax, j);
                        break;
                    } else if (j == LB) {
                        possible = false;
                        break;
                    }
                }
            }
        }
        if (possible) {
            return {true, sol};
        } else {
            for (int br = LB+1; br <= UB; br++) {
                auto sl = try_solve(LB, br-1);
                auto sr = try_solve(br, UB);
                if (sl.first && sr.first) {
                    sol.clear();
                    for (auto& pr: sl.second) {sol.push_back(pr);}
                    for (auto& pr: sr.second) {sol.push_back(pr);}
                    return {true, sol};
                }
            }
            return {false, {}};
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);

    int n;
    cin >> n;
    arr0.resize(n), arr1.resize(n);
    vector<int> split_i = {0};
    for (int i = 0; i < n; i++) {
        cin >> arr0[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        if (arr0[i] == arr1[i] && i != 0 && i != n-1) {split_i.push_back(i);}
    }
    split_i.push_back(n-1);

    auto s = try_solve(0, n-1);
    if (s.first) {
        cout << "YES\n";
        cout << s.second.size() << '\n';
        for (auto& [l, r]: s.second) {
            if (l < r) {cout << "L " << l << ' ' << r << '\n';}
            else {cout << "R " << r << ' ' << l << '\n';}
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}

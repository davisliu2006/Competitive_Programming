#include <bits/stdc++.h>

using namespace std;

using pair_li = pair<long,int>;

struct edge {
    int i, u, v, l, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);

    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    vector<int> sorted(m);
    vector<vector<pair<pair_li,int>>> graph(n+1);
    for (int a = 0; a < m; a++) {
        edge& e = edges[a];
        e.i = a;
        sorted[a] = a;
        cin >> e.u >> e.v >> e.l >> e.c;
        graph[e.u].push_back({{-e.l, e.v}, e.i});
        graph[e.v].push_back({{-e.l, e.u}, e.i});
    }
    sort(sorted.begin(), sorted.end(), [&](int x, int y) {
        return edges[x].c > edges[y].c;
    });

    long cst = 0;
    vector<int8_t> exists(m, true);
    for (int& ii: sorted) {
        edge& e = edges[ii];
        exists[e.i] = false;
        vector<long> dist(n+1, LONG_MAX);
        priority_queue<pair_li> pq;
        pq.push({0, e.u});
        while (!pq.empty()) {
            pair_li curr = pq.top();
            pq.pop();
            if (dist[curr.second] != LONG_MAX) {continue;}
            dist[curr.second] = -curr.first;
            for (auto& [next, i]: graph[curr.second]) {
                if (exists[i]) {
                    pq.push({curr.first+next.first, next.second});
                }
            }
        }
        if (dist[e.v] > e.l) {exists[e.i] = true; cst += e.c;}
    }
    cout << cst << '\n';

    return 0;
}

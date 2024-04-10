#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> graph;
vector<int8_t> vis;
vector<pair<int,int>> edges;
vector<int8_t> color;
char colormap[] = {'R', 'B', 'G'};
void dfs(int curr, int8_t prevcolor) {
    vis[curr] = true;
    for (auto& [next, ei]: graph[curr]) {
        if (vis[next]) {continue;}
        color[ei] = !prevcolor;
        dfs(next, color[ei]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);

    int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    vis.resize(n+1);
    edges.resize(m);
    color.resize(m, 2);
    for (int i = 0; i < m; i++) {
        auto& [u, v] = edges[i];
        cin >> u >> v;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 1);
        }
    }
    for (int i = 0; i < m; i++) {
        cout << colormap[color[i]];
    }
    cout << '\n';

    return 0;
}

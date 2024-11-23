#include <bits/stdc++.h>

using namespace std;

struct node {
    int pos;
    int h;
    long t;
};
bool operator <(const node& x, const node& y) {
    return x.t < y.t;
}

int main() {
    ios::sync_with_stdio(false);
    cout << setprecision(15);

    int hull, nisland, nroute;
    cin >> hull >> nisland >> nroute;
    vector<vector<node>> graph(nisland+1);
    while (nroute--) {
        int x, y, t, h;
        cin >> x >> y >> t >> h;
        graph[x].push_back(node{y, h, -t});
        graph[y].push_back(node{x, h, -t});
    }
    int st, end;
    cin >> st >> end;

    vector<int> maxhull(nisland+1);
    priority_queue<node> pq;
    pq.push(node{st, hull, 0L});
    while (!pq.empty()) {
        node curr = pq.top();
        pq.pop();
        if (curr.h > maxhull[curr.pos]) {
            if (curr.pos == end) {cout << -curr.t << '\n'; return 0;}
            maxhull[curr.pos] = curr.h;
            for (node& next: graph[curr.pos]) {
                pq.push(node{next.pos, curr.h-next.h, curr.t+next.t});
            }
        }
    }
    cout << "-1\n";

    return 0;
}

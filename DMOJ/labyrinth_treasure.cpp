#include <bits/stdc++.h>

using namespace std;

using pair_i = pair<int,int>;
using pair_li = pair<long,int>;

vector<vector<pair_i>> rgraph;
vector<int> rdep;
vector<int> rtour;
vector<int> foccur;
vector<vector<int>> rlca;
void get_rtour(int curr) {
    if (foccur[curr] == -1) {foccur[curr] = rtour.size();}
    rtour.push_back(curr);
    for (auto& [t, next]: rgraph[curr]) {
        if (rdep[next] == -1) {
            rdep[next] = rdep[curr]-t;
            get_rtour(next);
            rtour.push_back(curr);
        }
    }
}
int get_rdist(int u, int v) {
    int l = foccur[u];
    int r = foccur[v];
    if (l > r) {swap(l, r);}
    int sz = log2(r-l+1);
    int lca = min(rlca[sz][l], rlca[sz][r-(1<<sz)+1], [&](int x, int y) {
        return rdep[x] < rdep[y];
    });
    return rdep[u]-rdep[lca]+rdep[v]-rdep[lca];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);

    int nr;
    cin >> nr;
    rgraph = vector<vector<pair_i>>(nr+1);
    for (int i = 1; i <= nr-1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        rgraph[u].push_back({-t, v});
        rgraph[v].push_back({-t, u});
    }

    // room lca
    rdep = vector<int>(nr+1, -1);
    rdep[1] = 0;
    foccur = vector<int>(nr+1, -1);
    rtour.reserve(nr*2);
    get_rtour(1);
    int rtour_sz = log2(rtour.size());
    rlca = vector<vector<int>>(rtour_sz+1, vector<int>(rtour.size()));
    rlca[0] = rtour;
    for (int sz = 1; sz <= rtour_sz; sz++) {
        for (int i = 0; i+(1<<sz) <= rtour.size(); i++) {
            rlca[sz][i] = min(rlca[sz-1][i], rlca[sz-1][i+(1<<(sz-1))], [&](int x, int y) {
                return rdep[x] < rdep[y];
            });
        }
    }

    // box graph
    int nb, trg;
    cin >> nb >> trg;
    vector<vector<pair_li>> bgraph(nb+1);
    vector<int> boxpos(nb+1);
    for (int bx = 1; bx <= nb; bx++) {cin >> boxpos[bx];}
    for (int bx = 1; bx <= nb; bx++) {
        int nk;
        cin >> nk;
        while (nk--) {
            int bx2;
            cin >> bx2;
            bgraph[bx].push_back({-get_rdist(boxpos[bx], boxpos[bx2]), bx2});
        }
    }

    // box dist
    vector<long> bdist(nb+1, LONG_MAX);
    priority_queue<pair_li> pq;
    int ns;
    cin >> ns;
    while (ns--) {
        int s;
        cin >> s;
        pq.push({-get_rdist(1, boxpos[s]), s});
    }
    while (!pq.empty()) {
        auto [t, curr] = pq.top();
        pq.pop();
        if (bdist[curr] != LONG_MAX) {continue;}
        bdist[curr] = -t;
        if (curr == trg) {break;}
        for (auto& [dt, next]: bgraph[curr]) {
            pq.push({t+dt, next});
        }
    }
    cout << (bdist[trg] == LONG_MAX? -1 : bdist[trg]) << '\n';

    return 0;
}

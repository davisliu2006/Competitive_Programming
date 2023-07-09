#include <bits/stdc++.h>

using namespace std;

int n, logn;
int table[10][10][1000][1000];
void init(vector<vector<int>> arr) {
    n = arr.size();
    logn = int(log2(n));
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            table[0][0][x][y] = arr[x][y];
        }
    }
    for (int sy = 1; sy <= logn; sy++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y+(1<<sy) <= n; y++) {
                table[0][sy][x][y] = min(table[0][sy-1][x][y],
                    table[0][sy-1][x][y+(1<<sy-1)]);
            }
        }
    }
    for (int sx = 1; sx <= logn; sx++) {
        for (int x = 0; x+(1<<sx) <= n; x++) {
            for (int y = 0; y < n; y++) {
                table[sx][0][x][y] = min(table[sx-1][0][x][y],
                    table[sx-1][0][x+(1<<sx-1)][y]);
            }
        }
    }
    for (int sx = 1; sx <= logn; sx++) {
        for (int sy = 1; sy <= logn; sy++) {
            for (int x = 0; x+(1<<sx) <= n; x++) {
                for (int y = 0; y+(1<<sy) <= n; y++) {
                    table[sx][sy][x][y] = min({
                        table[sx-1][sy-1][x][y],
                        table[sx-1][sy-1][x][y+(1<<sy-1)],
                        table[sx-1][sy-1][x+(1<<sx-1)][y],
                        table[sx-1][sy-1][x+(1<<sx-1)][y+(1<<sy-1)]
                    });
                }
            }
        }
    }
}
int query(int x0, int x1, int y0, int y1) {
    int sx = log2(x1-x0+1);
    int sy = log2(y1-y0+1);
    return min({
        table[sx][sy][x0][y0],
        table[sx][sy][x0][y1-(1<<sy)+1],
        table[sx][sy][x1-(1<<sx)+1][y0],
        table[sx][sy][x1-(1<<sx)+1][y1-(1<<sy)+1]
    });
}

int main() {
    ios::sync_with_stdio(false);
    cout << setprecision(15);

    /*init({
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    });
    cout << query(0, 3, 1, 3) << '\n';*/

    return 0;
}

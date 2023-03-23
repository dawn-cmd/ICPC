#include "bits/stdc++.h"
using namespace std;
int dfs(const int &x, const int &y, vector<string> &g, vector<vector<int>> &vis) {
    if (x < 0 || x >= g.size() || y < 0 || y >= g[x].size() || vis[x][y] || (g[x][y] != ' ' && g[x][y] != '.')) {
        return 0;
    }
    vis[x][y] = 1;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int ans = 0;
    if (g[x][y] == '.') {
        ans++;
        g[x][y] = ' ';
    }
    for (const auto &d: directions) {
        int nextX = x + d[0];
        int nextY = y + d[1];
        ans += dfs(nextX, nextY, g, vis);
    }
    return ans;
}
int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<string> g(n);
    vector<vector<int>> vis(n);
    getline(cin, g[0]);
    for (int i = 0; i < n; ++i) {
        getline(cin, g[i]);
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << g[i][j];
    //     }
    //     cout << '\n';
    // }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vis[i].emplace_back(0);
        }
    }
    int cntEntrance = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] < 'A' || g[i][j] > 'W') {
                continue;
            }
            g[i][j] = ' ';
            if (dfs(i, j, g, vis)) {
                ++cntEntrance;
            }
            g[i][j] = 'X';
        }
    }
    int cntDots = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cntDots += (int) (g[i][j] == '.');
        }
    }
        cout << cntEntrance << ' ' << cntDots << '\n';
    return 0;
}

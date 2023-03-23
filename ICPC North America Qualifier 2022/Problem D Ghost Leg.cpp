#include "bits/stdc++.h"
using namespace std;
int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> rungs(m);
    for (int i = 0; i < m; ++i) {
        cin >> rungs[i];
    }
    vector<int> permuted(n + 1);
    for (int i = 1, tmp; i <= n; ++i) {
        tmp = i;
        for (const auto &rung: rungs) {
            if (tmp == rung) {
                tmp++;
                continue;
            }
            if (tmp == rung + 1) {
                tmp--;
                continue;
            }
        }
        permuted[tmp] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cout << permuted[i] << '\n';
    }
    return 0;
}

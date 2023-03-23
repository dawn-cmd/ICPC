#include "bits/stdc++.h"
using namespace std;
int main() {
    int n;
    cin >> n;
    unordered_map<int, int> h;
    for (int i = 2, tmp; i <= n; ++i) {
        cin >> tmp;
        h[tmp + 1] = i;
    }
    h[0] = 1;
    for (int i = 0; i < n; ++i) {
        cout << h[i] << ' ';
    }
    cout << '\n';
}

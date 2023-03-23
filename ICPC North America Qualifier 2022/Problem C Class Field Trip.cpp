#include "bits/stdc++.h"
using namespace std;
void update(string &ans, string &ori, int &id) {
    ans += ori[id];
    id++;
}
int main() {
    string a;
    string b;
    cin >> a >> b;
    string ans;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            update(ans, a, i);
            continue;
        }
        update(ans, b, j);
    }
    ans += a.substr(i) + b.substr(j);
    cout << ans << '\n';
    return 0;
}

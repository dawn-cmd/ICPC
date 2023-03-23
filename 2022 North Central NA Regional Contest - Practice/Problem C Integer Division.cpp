#include "bits/stdc++.h"
using namespace std;
using LL = long long;
LL calc(const LL &n) {
    LL ans = 0;
    for (LL i = n - 1; i >= 1; --i) {
        ans += i;
    }
    return ans;
}
int main() {
    LL n;
    LL d;
    cin >> n >> d;
    unordered_map<LL, LL> cnts;
    for (LL i = 0, tmp; i < n; ++i) {
        cin >> tmp;
        cnts[tmp / d]++;
    }
    LL ans = 0;
    for (auto item: cnts) {
        ans += calc(item.second);
    }
    cout << ans << '\n';
}

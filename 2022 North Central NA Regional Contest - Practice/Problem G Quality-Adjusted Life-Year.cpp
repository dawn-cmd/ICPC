#include "bits/stdc++.h"
using namespace std;
int main() {
    int n;
    cin >> n;
    double period;
    double quality;
    double ans = 0;
    while (n--) {
        cin >> period >> quality;
        ans += period * quality;
    }
    cout.precision(10);
    cout << ans << '\n';
}

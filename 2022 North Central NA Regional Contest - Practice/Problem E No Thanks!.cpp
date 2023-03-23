#include "bits/stdc++.h"
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0, tmp; i < n; ++i) {
        cin >> tmp;
        nums.emplace_back(tmp);
    }
    sort(nums.begin(), nums.end());
    int ans = 0;
    int cur = -1;
    for (const auto &num: nums) {
        if (num != cur + 1) {
            ans += num;
        }
        cur = num;
    }
    cout << ans << '\n';
    return 0;
}

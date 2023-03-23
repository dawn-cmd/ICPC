#include "bits/stdc++.h"
using namespace std;
using LL = long long;
int main() {
    int n;
    cin >> n;
    vector<LL> nums;
    for (LL i = 0, tmp; i < n; ++i) {
        cin >> tmp;
        nums.emplace_back(tmp);
    }
    sort(nums.begin(), nums.end());
    LL hIndex = -1;
    for (LL i = nums.size() - 1; i >= 0; --i) {
        hIndex = max(hIndex, min((LL) (nums.size() - i), nums[i]));
    }
    cout << hIndex << '\n';
    return 0;
}

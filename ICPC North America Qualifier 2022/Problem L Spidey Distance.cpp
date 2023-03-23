#include "bits/stdc++.h"
using namespace std;
using LL = long long;
// countT takes value n and returns 2 * n^2 + 2 * n + 1
LL countT(const LL &n) {
    return 2 * n * n + 2 * n + 1;
}

// count takes parameters t and s and returns a vector containing two values
vector<LL> count(const LL &t, const LL &s) {
    // initialize anst with the result of countT applied to the smaller value between t and s
    LL anst = countT(min(s, t));
    // initialize anss with the result of countT applied to s
    LL anss = countT(s);
    // st starts with value s + 1
    LL st = s + 1;
    // tmp is used to accumulate a value
    LL tmp = 0;
    st -= 3;
    // extra is the difference between t and s
    LL extra = t - s;
    while (st > 0) {
        // if extra is positive
        if (extra > 0) {
            // add st * 4 to anst
            anst += st * 4;
            // decrement extra by 1
            extra -= 1;
        }
        // add st to tmp
        tmp += st;
        // decrement st by 3
        st -= 3;
    }
    // add tmp * 4 to anss
    anss += tmp * 4;
    // create a vector with values anst and anss and return it as result
    vector<LL> ans{anst, anss};
    return ans;
}

int main() {
    // read value s and t
    LL s;
    LL t;
    cin >> t >> s;
    // get result of the function count applied to parameters t and s
    vector<LL> ans = count(t, s);
    // tmp is the greatest common divisor between elements of ans
    LL tmp = gcd(ans[0], ans[1]);
    // divide all values in ans by tmp
    ans[0] /= tmp;
    ans[1] /= tmp;
    // if value in ans in position 1 is 1
    if (ans[1] == 1) {
        // print value in ans in position 0
        cout << ans[0] << '\n';
        // return 0
        return 0;
    }
    // print values in positions 0 and 1 of ans separated by '/'
    cout << ans[0] << '/' << ans[1] << '\n';
    // return 0
    return 0;
}

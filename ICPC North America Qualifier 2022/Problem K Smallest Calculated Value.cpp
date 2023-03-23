#include "bits/stdc++.h"
using namespace std;
int doOpt(const char &opt, const int &a, const int &b) {
    if (opt == '+') {
        return a + b;
    }
    if (opt == '-') {
        return a - b;
    }
    if (opt == '*') {
        return a * b;
    }
    if (opt == '/') {
        if (a % b != 0) {
            return 0x3f3f3f3f;
        }
        return a / b;
    }
    return 0x3f3f3f3f;
}
int calculate(const int &a, const int &b, const int &c, const vector<char> &opt) {
    int tmp;
    tmp = doOpt(opt[1], doOpt(opt[0], a, b), c);
    return tmp >= 0 ? tmp : 0x3f3f3f3f;
}
int main() {
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    vector<vector<char>> opts{
        {'+', '+'}, {'+', '-'}, {'+', '*'}, {'+', '/'},
        {'-', '+'}, {'-', '-'}, {'-', '*'}, {'-', '/'},
        {'*', '+'}, {'*', '-'}, {'*', '*'}, {'*', '/'},
        {'/', '+'}, {'/', '-'}, {'/', '*'}, {'/', '/'}
    };
    int ans = 0x3f3f3f3f;
    for (const auto &opt: opts) {
        // cout << calculate(a, b, c, opt) << ' ' << opt[0] << ' ' << opt[1] << '\n';
        ans = min(ans, calculate(a, b, c, opt));
    }
    cout << ans << '\n';
    return 0;
}

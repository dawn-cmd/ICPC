#include "bits/stdc++.h"
using namespace std;
using LL = long long;
int main() {
    LL n;
    LL h;
    LL v;
    cin >> n >> h >> v;
    cout << 4 * max(max(h * v, (n - h) * v), max(h * (n - v), (n - h) * (n - v))) << '\n';
}

#include "bits/stdc++.h"
using namespace std;
int main() {
    string s;
    double cap;
    cin >> s >> cap;
    cout.precision(14);
    cout << ((s.size() < cap) ? (s.size()) : (cap)) << '\n';
    return 0;
}

#include "bits/stdc++.h"
using namespace std;
int main() {
    string s;
    cin >> s;
    int i = 0, j = s.size() - 1;
    while (s[i] == s[j]) {
        i++;
        j--;
    }
    if (s[i] != '(' || s[j] != ')') {
        cout << "fix" << '\n';
        return 0;
    }
    cout << "correct" << '\n';
}

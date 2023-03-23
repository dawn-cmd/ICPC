#include "bits/stdc++.h"
using namespace std;

// Function to generate the smallest integer that can be formed using the unused digits of n
long long generateSmaller(const vector<int> &n_digits, const set<int> &used) {
    long long ans = 0;
    bool is_find = false;
    for (int i = n_digits[0] - 1; i >= 0; --i) {
        if (used.find(i) == used.end()) {
            is_find = true;
            ans = ans * 10 + i;
            break;
        }
    }
    if (!is_find) {
        return -1;
    }
    for (int i = 0; i < n_digits.size() - 1; ++i) {
        for (int j = 9; j >= 0; --j) {
            if (used.find(j) == used.end()) {
                ans = ans * 10 + j;
                break;
            }
        }
    }
    return ans;
}

// Function to generate the largest integer that can be formed using the unused digits of n
long long generateLarger(const vector<int> &n_digits, const set<int> &used) {
    long long ans = 0;
    bool is_find = false;
    for (int i = n_digits[0] + 1; i < 10; ++i) {
        if (used.find(i) == used.end()) {
            is_find = true;
            ans = ans * 10 + i;
            break;
        }
    }
    if (!is_find) {
        return -1;
    }
    for (int i = 0; i < n_digits.size() - 1; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (used.find(j) == used.end()) {
                ans = ans * 10 + j;
                break;
            }
        }
    }
    return ans;
}

int main() {
    long long n;
    cin >> n;
    vector<int> n_digits;
    set<int> used;

    // Extract digits of n and store them in n_digits and used set
    for (long long tmp = n; tmp; tmp /= 10) {
        n_digits.emplace_back(tmp % 10);
        used.emplace(tmp % 10);
    }
    reverse(n_digits.begin(), n_digits.end());

    // Generate the smallest and largest integers that can be formed using the same digits as n
    long long smaller = generateSmaller(n_digits, used);
    long long larger = generateLarger(n_digits, used);

    // Determine the closest of the two integers to n
    if (smaller < 0 && larger < 0) {
        cout << "Impossible" << '\n';
        return 0;
    }
    if (smaller < 0) {
        cout << larger << '\n';
    } else if (larger < 0) {
        cout << smaller << '\n';
    } else if (n - smaller == larger - n) {
        cout << smaller << ' ' << larger << '\n';
    } else {
        cout << (n - smaller < larger - n ? smaller : larger) << '\n';
    }
}

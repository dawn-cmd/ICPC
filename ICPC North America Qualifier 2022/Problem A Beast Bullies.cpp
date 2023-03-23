#include "bits/stdc++.h"
using namespace std;
using LL = long long;
// main function
int main() {
    // number of powers
    int n;
    // read the value of n
    cin >> n;
    // vector to store the powers
    vector<LL> power(n);
    // read the individual powers
    for (int i = 0; i < n; ++i) {
        cin >> power[i];
    }
    // sort the powers in ascending order
    sort(power.begin(), power.end());
    // store the attack power
    LL attack = 0;
    // current power
    LL curPower = 0;
    // index for the powers
    int i = n - 1;
    // index for finding a suitable power to merge with power[i]
    int j = i;
    // number of attacks required
    int ans = 1;
    // loop until all the powers are added to attack
    while (i >= 0) {
        // utilize power[i]
        curPower = power[i];
        // find another power with higher strength to merge with power[i] while attack is less than curPower
        while (curPower < attack && j >= 0) {
            --j;
            // if no more powers are left, break the inner loop, cannot merge with any power
            if (j == -1) {
                break;
            }
            // add the selected power to curPower
            curPower += power[j];
        }
        // if no more powers remain and curPower is still less than attack, means cannot reach final attack power
        if (j == -1 && curPower < attack) {
            // update answer to number of remaining powers, which were not utilized 
            ans = n - i - 1;
            break;
        }
        // if only the smallest power remains and it can lead to the required final power
        if (j == 0 && curPower >= attack) {
            // means all the powers are utilized, answer is n
            ans = n;
            break;
        }
        // update i and j
        i = j - 1;
        attack += curPower;
        curPower = 0;
        j = i;
    }
    cout << ans << '\n';
    return 0;
}

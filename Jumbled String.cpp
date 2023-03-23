// include standard library for basic functions
#include "bits/stdc++.h"

// Declare namespace
using namespace std;

// Define long long variable type
using LL = long long;

// Function to get sum of consecutive numbers
LL getNum(LL n) {
    // Initialize variables
    LL cur = 0;
    LL sum = 0;

    // Iterate over until the sum is less than given number
    while (sum < n) {
        // Add current number to sum and increase current number
        sum += cur;
        cur++;
    }

    // Return cur if sum equals given number, else return -1
    return sum == n ? cur : -1;
}

// Main function
int main() {
    // Initialize variables
    LL n00;// number of 00
    LL n01;// number of 01
    LL n10;// number of 10
    LL n11;// number of 11

    // Take input from user 
    cin >> n00 >> n01 >> n10 >> n11;

    // If all four numbers equal to 0, print 0 and return 
    if (n00 + n01 + n10 + n11 == 0) {
        cout << "0" << '\n';
        return 0;
    }

    // Get the consecutive number summing upto n00 
    LL n0 = getNum(n00);

    // Condition if n0 equals 0
    if (n0 == 0)
        n0 = (n01 || n10);

    // Get the consecutive number summing upto n11
    LL n1 = getNum(n11);

    // Condition if n1 equals 0
    if (n1 == 0)
        n1 = (n10 || n01);

    // If conditions don't hold, print "impossible" and return
    if (n0 == -1 || n1 == -1 || n01 + n10 != n0 * n1) {
        cout << "impossible" << '\n';
        return 0;
    }

    // Create a vector of length n0+n1
    vector<LL> nums(n0 + n1);

    // Iterate through the vector and assign values 0 or 1 
    for (int i = 0; i < nums.size(); ++i)
        nums[i] = (i < n0) ? 0 : 1;

    // Declare the value of the first one 
    LL firstOne = n0;

    // Initialize the sums of 01 and 10
    LL cur01 = n0 * n1;
    LL cur10 = 0;

    // Declare usedOne as 0
    LL usedOne = 0;

    // Iterate while the sums of both 01 and 10 hold
    while (cur01 > n01 && cur10 < n10) {
        // If the firstOne equals usedOne, then 
        if (firstOne == usedOne) {
            // Increase usedOne
            usedOne++;

            // Assign the firstOne to usedOne + n0
            firstOne = usedOne + n0;
            continue;
        }
        // Declare step as the minimum of cur01 - n01 and firstOne - usedOne 
        LL step = min(cur01 - n01, firstOne - usedOne);

        // Swap the elements at position firstOne and firstOne - step 
        swap(nums[firstOne], nums[firstOne - step]);

        // Decrease firstOne by step
        firstOne -= step;
        
        // Decrease cur01 and increase cur10 by step 
        cur01 -= step;
        cur10 += step;
    }

    // Iterate over num and print out values
    for (const auto &num: nums)
        cout << num;

    // Print new line
    cout << '\n';

    // Return 0
    return 0;
}

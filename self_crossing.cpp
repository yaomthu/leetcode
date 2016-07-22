/**
 * Self crocssing
 * You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

Example 1:
Given x = [2, 1, 1, 2],
┌───┐
│   │
└───┼──>
    │

Return true (self crossing)
Example 2:
Given x = [1, 2, 3, 4],
┌──────┐
│      │
│
│
└────────────>

Return false (not self crossing)
solution:
a good solution can be referred from https://leetcode.com/discuss/88054/java-oms-with-explanation
// Categorize the self-crossing scenarios, there are 3 of them:
// 1. Fourth line crosses first line and works for fifth line crosses second line and so on...
// 2. Fifth line meets first line and works for the lines after
// 3. Sixth line crosses first line and works for the lines after

 */

#include <iostream>
#include <vector>
using namespace std;

namespace self_crossing {
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() < 4)
            return false;
        for (int i = 3; i < x.size(); i++) {
            if (x[i] >= x[i-2] && x[i-1] <= x[i-3])
                return true;
            if (i >= 4) {
                if (x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2])
                    return true;
            }
            if (i >= 5) {
                if (x[i-2] >= x[i-4] && x[i-1] <= x[i-3] && x[i-1] + x[i-5] >= x[i-3] && x[i] + x[i-4] >= x[i-2])
                    return true;
            }
        }
        return false;
    }
};
}

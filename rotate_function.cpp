/**
 * Rotate function
 * Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
solution:
F1 = F0 + total - 4a4
F2 = F1 + total - 4a3
F3 = F2 + total - 4a2
 */

#include <iostream>
#include <vector>
using namespace std;
namespace rotate_function {
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) {
            return 0;
        }
        long long total = 0;
        int ans;
        for (auto num : A) {
            total += num;
        }
        int fn = 0;
        for (int i = 0; i < A.size(); i++) {
            fn += i * A[i];
        }
        ans = fn;
        for (int index = A.size() - 1; index >= 1; index--) {
            fn = fn + total - A.size() * A[index];
            if (fn > ans) {
                ans = fn;
            }
        }
        return ans;
    }
};
}

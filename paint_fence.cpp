/**
 * Paint fence
 * There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.
 */

#include <iostream>
using namespace std;

namespace paint_fence {
class Solution {
public:
    int numWays(int n, int k) {
        int a = k, b = k*k;
        int c;
        if (n <= 0)
            return 0;
        else if (n == 1)
            return a;
        else if (n == 2)
            return b;
        for (int i = 3; i <= n; i++) {
            c = (k-1) * (a+b);
            a = b;
            b = c;
        }
        return c;
    }
};
}

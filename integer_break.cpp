/**
 * Integer Break
 * Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.

Hint:

There is a simple O(n) solution to this problem.Show More Hint

Solution: 有一个定理，f(n-3)*3 > f(n) if n > 4, 所以就一直拆3.
Space complexity: O(1)
Time complexity: O(n)
 */
#include <iostream>
using namespace std;

namespace integer_break {
class Solution {
public:
    int integerBreak(int n) {
        switch (n) {
            case 2: return 1;
            case 3: return 2;
            case 4: return 4;
            default:
                break;
        }
        int ans = 1;
        while(n > 4) {
            ans *= 3;
            n -= 3;
        }
        ans *= n;
        return ans;
    }
};
}

int main_integer_break() {
  int n = 10;
  cout << (new integer_break::Solution())->integerBreak(n) << endl;
}

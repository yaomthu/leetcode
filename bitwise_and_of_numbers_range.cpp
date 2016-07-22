/**
 * Bitwise and numbers range
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
solution: m 和 n 从高位往低位比较，如果相同则继续，如果不同则退出。在比较中，如果某位为1，则对结果该位置1.
 */

#include <iostream>
using namespace std;
namespace bitwise_and_numbers_range {
class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int ans = 0;
    for (int i=31; i>=0; i--) {
      if ((m & 1<<i) != (n & 1<<i))
        return ans;
      if ((m & 1<<i) != 0)
        ans |= 1<<i;
    }
    return ans;
  }
};
}

int main_bitwise_and_numbers_range() {
  cout << (new bitwise_and_numbers_range::Solution())->rangeBitwiseAnd(3,7);
}

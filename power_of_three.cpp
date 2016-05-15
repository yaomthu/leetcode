/*
 * Power of Three
 * Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

solution: 对于任意一个素数a，假设它的指数次幂为b，那么a的最大指数次幂对b取余肯定等于0.
time complexity：O(1)
space complexity: 0
 */
#include <iostream>
using namespace std;

namespace power_of_three {
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && 1162261467%n == 0;
    }
};
}
int main_power_of_three() {
  if ((new power_of_three::Solution())->isPowerOfThree(27)) {
    cout << "yes";
  } else {
    cout << "no";
  }
}

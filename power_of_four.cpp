/*
 * Power of Four
 * Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
 *
 */

#include <iostream>
using namespace std;
namespace power_of_four {
class Solution {
public:
    bool isPowerOfFour(int num) {
      return num>0 && (num & (num-1)) == 0 && (num & 0xaaaaaaaa) == 0;
    }
};
}
int main_power_of_four() {
  if ((new power_of_four::Solution())->isPowerOfFour(16)) {
    cout << "true";
  } else {
    cout << "false";
  }
}

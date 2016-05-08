/**
 * Counting Bits
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 */
#include <iostream>
#include <vector>
using namespace std;

namespace counting_bits {
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        ans[0] = 0;
        for(int i=1; i<=num; i++)
            ans[i] = 1 + ans[i&(i-1)];
        return ans;
    }
};
}

int main_counting_bits() {
  vector<int> ans = (new counting_bits::Solution())->countBits(5);
  for (auto num : ans) {
    cout << num << " ";
  }
}

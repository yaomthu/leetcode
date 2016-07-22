/**
 * Maximum product subarray
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

solution: 使用positive记录包含该元素的乘积大于0的结果或者1，negative记录包含该元素的乘积小于0的结果或者1.
time complexity: O(n)
space complexity: O(1)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace maximum_product_subarray {
class Solution {
public:
    int maxProduct(vector<int>& A) {
        if (A.empty())
            return 0;
        int positive = 1, negative = 1;
        int ans = INT_MIN;
        for (auto num : A) {
            int big = positive * num;
            int small = negative * num;
            if (big < small)
                swap(big, small);
            if (big > ans)
                ans = big;
            if (big > 1)
                positive = big;
            else
                positive = 1;
            if (small < 0)
                negative = small;
            else
                negative = 1;
        }
        return ans;
    }
};
}

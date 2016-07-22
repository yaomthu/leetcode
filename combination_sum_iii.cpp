/**
 * Combination sum iii
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
 */

#include <iostream>
#include <vector>
using namespace std;

namespace combination_sum_iii {
class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        if (k <= 0 || n < k)
            return ans;
        vector<int> record;
        dfs(ans, record, k, n, 1);
        return ans;
    }
    void dfs(vector<vector<int> >& ans, vector<int>& record, int k, int n, int start) {
        if (k == 0) {
            if (n == 0)
                ans.push_back(record);
            return;
        }
        if (n == 0)
            return;
        for (int index = start; index <= 9 && index <= n; index++) {
            record.push_back(index);
            dfs(ans, record, k-1, n-index, index+1);
            record.pop_back();
        }
    }
};
}

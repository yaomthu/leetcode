/**
 * Factor combinations
 * Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note:
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples:
input: 1
output:
[]
input: 37
output:
[]
input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
 */

#include <iostream>
#include <vector>
using namespace std;

namespace factor_combinations {
class Solution {
public:
    vector<vector<int> > getFactors(int n) {
        vector<vector<int> > ans;
        if (n <= 1)
            return ans;
        vector<int> record;
        dfs(ans, record, n, 2);
        return ans;
    }
    void dfs(vector<vector<int> >& ans, vector<int>& record, int n, int start) {
        int size = record.size();
        for (int x = start; x * x <= n; x++) {
            if (n % x == 0) {
                record.push_back(x);
                record.push_back(n/x);
                ans.push_back(record);
                record.pop_back();
                dfs(ans, record, n/x, x);
                record.resize(size);
            }
        }
    }
};
}

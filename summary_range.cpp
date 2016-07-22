/**
 * Summary Ranges
 * Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace summary_range{
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int start = 0;
        while (start < nums.size()) {
            string temp = to_string(nums[start]);
            int end = start+1;
            while (end < nums.size() && nums[end]-nums[end-1] == 1)
                end++;
            if (end-1 > start) {
                temp += "->" + to_string(nums[end-1]);
            }
            ans.push_back(temp);
            start = end;
        }
        return ans;
    }
};
}

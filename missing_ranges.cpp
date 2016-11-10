/**
 * missing ranges
 * Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
 */

#include <iostream>
#include <vector>
using namespace std;

namespace missing_ranges {
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        if (nums.empty()) {
            ans.push_back(getRange(lower, upper));
            return ans;
        }
        if (nums[0] > lower)
            ans.push_back(getRange(lower, nums[0]-1));
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] + 1 < nums[i+1]) {
                ans.push_back(getRange(nums[i]+1, nums[i+1]-1));
            }
        }
        if (nums.back() < upper)
            ans.push_back(getRange(nums.back()+1, upper));
        return ans;
    }

    string getRange(int start, int end) {
        string res = to_string(start);
        if (end > start)
            res += "->" + to_string(end);
        return res;
    }
};
}

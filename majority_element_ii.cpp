/**
 * Majority element ii
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. T
 * he algorithm should run in linear time and in O(1) space.
 */

#include <iostream>
#include <vector>
using namespace std;

namespace majority_element_ii {
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        if (nums.empty())
            return ans;
        vector<pair<int,int> > record;
        for (auto num : nums) {
            if (record.empty())
                record.push_back(make_pair(num, 1));
            else if (record.size() == 1) {
                if (record[0].first == num)
                    record[0].second++;
                else
                    record.push_back(make_pair(num, 1));
            } else {
                if (record[0].first == num)
                    record[0].second++;
                else if (record[1].first == num)
                    record[1].second++;
                else {
                    record[1].second--;
                    if (record[1].second == 0)
                        record.pop_back();
                    record[0].second--;
                    if (record[0].second == 0)
                        record.erase(record.begin());
                }
            }
        }
        for (int i = 0; i < record.size(); i++) {
            int count = 0;
            for (auto num : nums)
                if (num == record[i].first)
                    count++;
            if (count > (float)nums.size()/3)
                ans.push_back(record[i].first);
        }
        return ans;
    }
};
}

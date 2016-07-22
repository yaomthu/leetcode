/**
 * russina doll envelopes
 * You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

 solution: 对数组进行排序，排序原则是按第一维升序排序，如果第一维相同，则按第二维降序排序。然后根据第二维使用“求解最大递增序列长度”的方法进行求解。
 time complexity: O(nlogn)
 space complexity: O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace russian_doll_envelopes {
class Solution {
public:
    struct cmp {
        bool operator () (const pair<int,int>& a, const pair<int,int>& b) const {
            if (a.first < b.first || (a.first == b.first && a.second > b.second))
                return true;
            else
                return false;
        }
    };
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        if (envelopes.empty())
            return 0;
        sort(envelopes.begin(), envelopes.end(), cmp());
        vector<int> mis;
        mis.push_back(INT_MIN);
        for (auto entry : envelopes) {
            int index = search(mis, entry.second);
            if (index == mis.size())
                mis.push_back(entry.second);
            else {
                if (entry.second < mis[index])
                    mis[index] = entry.second;
            }
        }
        return mis.size()-1;
    }
    int search(vector<int>& mis, int num) {
        int left = 0, right = mis.size()-1;
        while (left <= right) {
            int mid = (left + right)/2;
            if (mis[mid] < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};
}
